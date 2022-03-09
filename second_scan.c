//
// Created by avishav on 28.2.2022.
//
#include <stdio.h>
#include <string.h>
#include "second_scan.h"
#include "symbol_table.h"
#include "string_manipulations.h"
#include "symbol.h"
#include "instruction.h"
#define LINE_LENGTH 81

#define END_OF_LABLE_SIGN ':'

#define MIN_IC 100

int is_symbol(char *str);

int is_extern(char *str);

int is_string(char *str);


int is_data(char *str);

int is_entry(char *str);

void second_scan(file source){
    symbol_table table;
    char line[LINE_LENGTH],*first_word_in_line;
    unsigned long ic=MIN_IC;
    FILE *src,*dest;
    table= get_symbol_table(source);
    src= fopen(get_name_am(source),"r");//todo add open file check
    dest= fopen(get_name_ob(source),"a");

    while ((fgets(line,LINE_LENGTH,src))!=NULL){
        first_word_in_line=strtok(line," \t");
        trim_whitespace(first_word_in_line);
        if(is_symbol(first_word_in_line)){
            first_word_in_line= strtok(NULL," \t");
            trim_whitespace(first_word_in_line);
        }
        if (!is_extern(first_word_in_line) && !is_string(first_word_in_line) && !is_data(first_word_in_line)){
            if (is_entry(first_word_in_line)){
                char *symbol_name;
                symbol to_update;
                symbol_name= strtok(NULL," \t");
                to_update= get_symbol_by_name(symbol_name);
                if (to_update!=NULL){
                    mark_entry(to_update);
                } else{
                    //todo print symbol dosent exist error

                }
            } else{
                instruction temp_instruction;
                temp_instruction= init_instruction(line, table, &ic);
                print_instruction(dest,temp_instruction);//todo error check
            }
        }
    }
}

int is_entry(char *str) {
    return !strcmp(str,".entry");
}

int is_data(char *str) {
    return !strcmp(str,".data");
}

int is_string(char *str) {
    return !strcmp(str,".string");
}

int is_extern(char *str) {
    return !strcmp(str,".extern");
}

int is_symbol(char *str) {
    char last_char=*(str+ strlen(str)-1);
    return last_char==END_OF_LABLE_SIGN;
}
