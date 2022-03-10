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
#include "parser.h"
#include "first_and_second_scan_constants.h"


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
        if(is_symbol_def(first_word_in_line)){
            first_word_in_line= strtok(NULL," \t");
            trim_whitespace(first_word_in_line);
        }
        if (!is_extern_def(first_word_in_line) && !is_string_def(first_word_in_line) && !is_data_def(first_word_in_line)){
            if (is_entry_def(first_word_in_line)){
                char *symbol_name;
                symbol to_update;
                symbol_name= strtok(NULL," \t");
                to_update= get_symbol_by_name(NULL, symbol_name);
                if (to_update!=NULL){
                    mark_entry(to_update);
                } else{
                    //todo print symbol dosent exist error

                }
            } else{
                instruction temp_instruction;
                temp_instruction= init_instruction(line, table, &ic, NULL, DOUBLE_DEFINITION_OF_LABEL);
                print_instruction(dest,temp_instruction);//todo error check
            }
        }
    }
}

