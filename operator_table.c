
#include <stdio.h>
#include <string.h>
#include "operator_table.h"
#include "addressing_mode.h"
#include "string_manipulations.h"

#define TABLE_SIZE 16
#define NUMBER_OF_ADDRESSING_METHODS 4

struct allowed_addressing{
    unsigned int immediate :1;
    unsigned int direct :1;
    unsigned int index :1;
    unsigned int register_direct :1;
};

struct operator{
    char *name;
    int funct;
    int opcode;
    int num_of_operands;
    struct allowed_addressing source;
    struct allowed_addressing dest;
};

operator get_operator_by_name(char *name){
    int i;
    operator result;
    i=0;
    result=NULL;
    static struct operator operators[]={
        {"mov",0,0,2,{1,1,1,1},{0,1,1,1}},
        {"cmp",0,1,2,{1,1,1,1},{1,1,1,1}},
        {"add",10,2,2,{1,1,1,1},{0,1,1,1}},
        {"sub",11,2,2,{1,1,1,1},{0,1,1,1}},
        {"lea",0,4,2,{0,1,1,0},{0,1,1,1}},
        {"clr",10,5,1,{0,0,0,0},{0,1,1,1}},
        {"not",11,5,1,{0,0,0,0},{0,1,1,1}},
        {"inc",12,5,1,{0,0,0,0},{0,1,1,1}},
        {"dec",13,5,1,{0,0,0,0},{0,1,1,1}},
        {"jmp",10,9,1,{0,0,0,0},{0,1,1,0}},
        {"bne",11,9,1,{0,0,0,0},{0,1,1,0}},
        {"jsr",12,9,1,{0,0,0,0},{0,1,1,0}},
        {"red",0,12,1,{0,0,0,0},{0,1,1,1}},
        {"prn",0,13,1,{0,0,0,0},{1,1,1,1}},
        {"rts",0,14,0,{0,0,0,0},{0,0,0,0}},
        {"stop",0,15,0,{0,0,0,0},{0,0,0,0}}
    };
    name= trim_whitespace(name);
    while ((i<TABLE_SIZE)&&(result==NULL)){
        if (!strcmp(name,operators[i].name)){
            result = operators+i;
        }
        i++;
    }
    return result;
}

int get_opcode(operator op){
    return op->opcode;
}

int get_funct(operator op){
    return op->funct;
}

int get_n_operands(operator op){
    return op->num_of_operands;
}

unsigned int is_allowed_addressing(struct allowed_addressing allowed, addressing_mode mode){
    unsigned int result;
    result=0;
    switch (mode){
        case IMMEDIATE:
            result=allowed.immediate;
            break;
        case DIRECT:
            result=allowed.direct;
            break;
        case REGISTER_DIRECT:
            result=allowed.register_direct;
            break;
        case INDEX:
            result=allowed.index;
    }
    return result;
}

unsigned int is_legal_source_addressing_mode(operator op,addressing_mode mode){
    return is_allowed_addressing(op->source,mode);
}

unsigned int is_legal_dest_addressing_mode(operator op,addressing_mode mode){
    return is_allowed_addressing(op->dest,mode);
}