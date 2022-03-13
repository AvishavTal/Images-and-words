//
// Created by avishav on 28.2.2022.
//

#include "instruction.h"
#include "word.h"
#include <stdlib.h>
#include "operator_table.h"
#include "string_manipulations.h"
#include "errors.h"
#include "ARE.h"
#include "register_table.h"
#include <stdio.h>

#define MAX_N_WORDS 6

/*indexes of the words in the word list of the instruction*/
#define OP_WORD_INDEX 0
#define OPERANDS_INFO_WORD_INDEX 1
#define SOURCE_ADDRESS_WORD_INDEX 2
#define SOURCE_OFFSET_WORD_INDEX 3
#define DEST_ADDRESS_WORD_INDEX 4
#define DEST_OFFSET_WORD_INDEX 5


/*Indexes in the arguments list*/
#define DEST_ARG_INDEX 1
#define SOURCE_ARG_INDEX 0

/*number of arguments required*/
#define REQUIRED_TWO 2
#define REQUIRED_ONE 1
#define NO_ARGS_REQUIRED 0


#define IMMEDIATE_SIGN '#'


#define LEFT_BRAKET '['
#define RIGHT_BRAKET ']'


struct instruction{
    int n_words;/*number of words in the machine code*/
    word words[MAX_N_WORDS];
    operator op;
    addressing_mode dest_addressing;
    addressing_mode source_addressing;

};

void set_operator(instruction to_set, char *name, unsigned long *ic, error *err);

void set_args(instruction to_set, symbol_table symbols, char **arguments_list, unsigned long n_args, unsigned long *ic,
              error *err);

void
set_two_args(instruction to_set, symbol_table symbols, char *source_arg, char *dest_arg, unsigned long *ic, error *err);

void set_one_arg(instruction to_set, symbol_table symbols, char *dest_arg, unsigned long *ic, error *err);

void
build_second_word(instruction to_set, symbol_table symbols, char *source, char *dest, unsigned long *ic, error *err);

addressing_mode recognize_addressing_mode(char *operand);

void set_addressing_modes(instruction to_set, char *source, char *dest, error *err);

int is_immediate(char *operand);

int is_index(char *operand);

int is_register_direct(char *operand);

void print_instruction(FILE *dest, instruction to_print){
    int i=0;
    for (; i<to_print->n_words ; ++i) {
        print_word(dest,to_print->words[i]);
    }
}

instruction init_instruction(char *line, symbol_table symbols, unsigned long ic, int *n_words, error *err) {
    instruction result;
    char *opname;
    trim_whitespace(line);
    opname=get_first_word_in_line(line);
    result=(instruction) malloc(sizeof(struct instruction));
    result->n_words=0;
    set_operator(result, opname, &ic, err);
    if(*err==NOT_ERROR){
        char **arguments;
        unsigned long op_len,arguments_len;
        op_len= strlen(opname);
        arguments=(char **) malloc(sizeof(char *));
        arguments_len= split(line+op_len+1,arguments,", \t");
        set_args(result, symbols, arguments, arguments_len, &ic, err);
    }
    return result;
}

void set_args(instruction to_set, symbol_table symbols, char **arguments_list, unsigned long n_args, unsigned long *ic,
              error *err) {
    int required_number_of_operands;
    required_number_of_operands= get_n_operands(to_set->op);
    if(n_args>required_number_of_operands){
        *err=TOO_MANY_ARGS;
    } else if (n_args<required_number_of_operands){
        *err=TOO_FEW_ARGS;
    } else{
        switch (required_number_of_operands) {
            case REQUIRED_ONE:
                set_one_arg(to_set,symbols,*arguments_list,ic,err);
                break;
            case REQUIRED_TWO:
                set_two_args(to_set,symbols,arguments_list[SOURCE_ARG_INDEX],arguments_list[DEST_ARG_INDEX],ic,err);
                break;
            case NO_ARGS_REQUIRED:
                break;
            default:
                fprintf(stderr,"we have a problem");
        }
    }
}

void
build_second_word(instruction to_set, symbol_table symbols, char *source, char *dest, unsigned long *ic, error *err) {
    set_addressing_modes(to_set,source,dest,err);
    if(*err==NOT_ERROR){
        int funct;
        funct= get_funct(to_set->op);
        set_address(to_set->words[OPERANDS_INFO_WORD_INDEX],*ic);
        (*ic)++;
        set_funct(to_set->words[OPERANDS_INFO_WORD_INDEX],funct);
        set_are(to_set->words[OPERANDS_INFO_WORD_INDEX],ABSOLUTE);
        set_src_addressing(to_set->words[OPERANDS_INFO_WORD_INDEX],to_set->source_addressing);
        set_dest_addressing(to_set->words[OPERANDS_INFO_WORD_INDEX],to_set->dest_addressing);
    }


}

void set_addressing_modes(instruction to_set, char *source, char *dest, error *err) {
    to_set->dest_addressing = recognize_addressing_mode(dest);
    to_set->source_addressing = recognize_addressing_mode(source);
    if(!is_legal_dest_addressing_mode(to_set->op,to_set->dest_addressing) ||
                            ((source!=NULL)&&(!is_legal_source_addressing_mode(to_set->op,to_set->source_addressing)))){
        *err=ILLEGAL_ADDRESSING;
    }
}

addressing_mode recognize_addressing_mode(char *operand) {
    addressing_mode result;
    result=DEFAULT;
    if(operand){
        if (is_immediate(operand)){
            result=IMMEDIATE;
        } else if(is_index(operand)){
            result=INDEX;
        } else if(is_register_direct(operand)){
            result=REGISTER_DIRECT;
        } else{
            result=DIRECT;
        }
    }
    return result;
}

int is_register_direct(char *operand) {
    return get_register_by_name(operand)!=NULL;
}

int is_index(char *operand) {
    int result=0,len,left_diteceted=0,i=0;
    operand=trim_whitespace(operand);
    len= strlen(operand);
    while ((result==0)&&(i<len)){
        if ((operand[i]==RIGHT_BRAKET)&&(left_diteceted)){
            result=1;
        }
        if(operand[i]==LEFT_BRAKET){
            left_diteceted=1;
        }
        i++;
    }
    return result;
}

int is_immediate(char *operand) {
    trim_whitespace(operand);
    return *operand==IMMEDIATE_SIGN;
}

void set_one_arg(instruction to_set, symbol_table symbols, char *dest_arg, unsigned long *ic, error *err) {

}

void set_two_args(instruction to_set, symbol_table symbols, char *source_arg, char *dest_arg, unsigned long *ic,
                  error *err) {

}

void set_operator(instruction to_set, char *name, unsigned long *ic, error *err) {
    to_set->op= get_operator_by_mame(name);
    if(to_set->op==NULL){
        *err=UNDEFINED_OPERATOR;
    } else{
        int opcode;
        opcode= get_opcode(to_set->op);
        set_address(to_set->words[OP_WORD_INDEX], *ic);
        (*ic)++;
        set_opcode(to_set->words[OP_WORD_INDEX], opcode);
        set_are(to_set->words[OP_WORD_INDEX], ABSOLUTE);
    }
}
