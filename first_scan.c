//
// Created by Sapir on 10.3.2022.
//
#include "first_scan.h"
#include "data_image.h"
#include <string.h>
#include "symbol_table.h"
#include "string_manipulations.h"
#include "instruction.h"
#include "parser.h"
#include "first_and_second_scan_constants.h"
#include "system_errors.h"

#define MIN_DC 0
#define true 1
#define false 0
#define  NOT_SYMBOL -1

void pull_symbol_name(char *first_word, char *dest);

void check_entry_definition_syntax(char *line, error *err);

void check_symbol_definition_syntax(char *line, error *err);

void check_data_definition_syntax(char *line, error *err);

void check_string_definition_syntax(char *line, error *err);

void check_extern_definition_syntax(char *line, error *err);

void check_instrucion_line_syntax(char *line, error *err);

void first_scan(file source) {
    /* variables declaration */
    symbol_table symbols;
    data_image image;
    FILE *src;
    error err;
    long ic, dc;
    unsigned long line_num;
    int  words_num;
    char line[LINE_LENGTH],*temp_line, *first_word_in_line, *second_word_in_line, symbol_name[LINE_LENGTH];
    boolean is_symbol;

    /*set variables */
    ic = MIN_IC;
    dc = MIN_DC;
    line_num = 0;
    symbols = get_symbol_table(source);
    image=get_data_image(source);
    src = fopen(get_name_am(source), "r");
    if (!is_open_file_succeeded(src,false, get_name_am(source))){
        mark_first_scan_failed(source);
    } else{
        while ((fgets(line, LINE_LENGTH, src)) != NULL) {
            is_symbol=false;
            err = NOT_ERROR;
            line_num ++;
            temp_line= trim_whitespace(line);
            if (!(is_comment(line) || is_empty(line))) { /* if this line is not a blank line or a comment line */
                first_word_in_line= str_tok(temp_line," \t");
                if (is_entry_def(first_word_in_line)) {
                    check_entry_definition_syntax(temp_line,&err);
                } else{
                    if (is_symbol_def(first_word_in_line)) { /* if this line starts with symbol */
                        is_symbol = true;
                        pull_symbol_name(first_word_in_line, symbol_name);
                        check_symbol_definition_syntax(temp_line,&err);
                        first_word_in_line= str_tok(NULL," \t");/*first_word_in_line is the first after the symbol definition*/
                        temp_line=temp_line+ strlen(symbol_name)+1;
                    }
                    if (is_data_def(first_word_in_line)|| is_string_def(first_word_in_line)){
                        long first_word_length;
                        first_word_length= strlen(first_word_in_line);
                        if (is_symbol){
                            add_symbol(symbols, symbol_name, dc, false, false, true, false, &err);
                        }
                        if (is_data_def(first_word_in_line)){
                            check_data_definition_syntax(temp_line,&err);
                            add_data_line(image,dc,temp_line+first_word_length+1,&words_num,&err);
                        } else if (is_string_def(first_word_in_line)){
                            check_string_definition_syntax(temp_line,&err);
                            add_string(image,dc,temp_line+first_word_length+1,&words_num,&err);
                        }
                        dc+=words_num;
                    }
                    else if (is_extern_def(first_word_in_line)) {
                        int first_word_length;
                        first_word_length= strlen(first_word_in_line);
                        check_extern_definition_syntax(temp_line,&err);
                        add_symbol(symbols, temp_line+first_word_length+1, 0, false, true, false, false,
                                   &err);
                    } else{ /*this line is an instruction.*/
                        instruction temp_instruction;
                        check_instrucion_line_syntax(temp_line,&err);
                        if (is_symbol){
                            add_symbol(symbols, symbol_name, ic, false, false, false, true, &err);
                        }
                        temp_instruction= init_instruction(temp_line,NULL,ic,&err);
                        ic+= get_n_words(temp_instruction);
                        delete_instruction(temp_instruction);
                    }
                }
            }
            if(err != NOT_ERROR){
                mark_first_scan_failed(source);
                print_error(line_num, err);
            }
        }

        set_final_dc(source,dc);
        set_final_ic(source,ic);
        update_addresses(image,ic);
        update_addresses_of_data_symbols(symbols,ic);
    }
}

void check_instrucion_line_syntax(char *line, error *err) {

}

void check_extern_definition_syntax(char *line, error *err) {

}

void check_string_definition_syntax(char *line, error *err) {

}

void check_data_definition_syntax(char *line, error *err) {

}

void check_symbol_definition_syntax(char *line, error *err) {

}

void check_entry_definition_syntax(char *line, error *err) {

}

void pull_symbol_name(char *first_word, char *dest) {
    strcpy(dest,first_word);
    dest[strlen(first_word)-1]='\0';
}