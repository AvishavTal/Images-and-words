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
#include "errors.h"


void clean_up(file to_clean);

void second_scan(file source){
    symbol_table symbols;
    long line_number=0;
    char *temp_line,line[LINE_LENGTH],*first_word_in_line;
    unsigned long ic=MIN_IC;
    FILE *src,*dest;
    error error1=NOT_ERROR;
    symbols= get_symbol_table(source);
    src= fopen(get_name_am(source),"r");
    dest= fopen(get_name_ob(source),"a");
    if(dest==NULL){
        fprintf(stderr,"problem with opening output file");
        exit(1);
    }
    mark_ob_file_exist(source);
    while ((fgets(line,LINE_LENGTH,src))!=NULL){
        temp_line=line;
        line_number++;
        if (!is_comment(temp_line)&&!is_empty(temp_line)){
            first_word_in_line=str_tok(temp_line," \t");
            first_word_in_line= trim_whitespace(first_word_in_line);
            if(is_symbol_def(first_word_in_line)){
                temp_line=line+ strlen(first_word_in_line)+1;
                first_word_in_line= str_tok(NULL," \t");
                first_word_in_line=trim_whitespace(first_word_in_line);
            }
            if (!is_extern_def(first_word_in_line) && !is_string_def(first_word_in_line) && !is_data_def(first_word_in_line)){
                if (is_entry_def(first_word_in_line)){
                    char *symbol_name;
                    symbol to_update;
                    symbol_name= str_tok(NULL," \t");
                    to_update= get_symbol_by_name(symbols, symbol_name);
                    if (to_update!=NULL){
                        mark_entry(to_update);
                    } else{
                        error1=UNDEFINED_SYMBOL;
                    }
                } else{
                    int n_words=0;
                    instruction temp_instruction;
                    temp_instruction= init_instruction(temp_line, symbols, ic, &n_words, &error1);
                    ic+=n_words;
                    if(is_ob_file_exist(source)){
                        print_instruction(dest,temp_instruction);
                    }
                    delete_instruction(temp_instruction);
                }
                if (error1!=NOT_ERROR){
                    print_error(line_number,error1);
                    error1=NOT_ERROR;
                    mark_second_scan_failed(source);
                    clean_up(source);
                }

            }
        }
    }
    data_image image= get_data_image(source);
    print_data(dest,image);
    fclose(src);
    if (is_ob_file_exist(source)){
        fclose(dest);
    }
}

void clean_up(file to_clean) {
    if (is_ob_file_exist(to_clean)){
        remove(get_name_ob(to_clean));
        mark_ob_file_not_exist(to_clean);
    }

}

