/*
* Created by Sapir on 10.3.2022.
*/
#include "first_scan.h"
#include "data_image.h"
#include <string.h>
#include "symbol_table.h"
#include "string_manipulations.h"
#include "instruction.h"
#include "parser.h"
#include "first_and_second_scan_constants.h"
#include "system_errors.h"
#include "boolean.h"

#define MIN_DC 0
#define SEPARATOR ','
#define QUOTATION_MARKS '"'

boolean check_if_syntax_correct(char* line, error *err);

void pull_symbol_name(char *first_word, char *dest);

void check_entry_definition_syntax(char *line, error *err);

void check_symbol_definition_syntax(char *line, error *err);

void check_data_definition_syntax(char *line, error *err);

void check_string_definition_syntax(char *line, error *err);

void check_extern_definition_syntax(char *line, error *err);

void check_instrucion_line_syntax(char *line, error *err);

void check_commas(char *line, error *err);

boolean check_for_comma_in_line(char *line);

void first_scan(file source) {
    /* variables declaration */
    symbol_table symbols;
    data_image image;
    FILE *src;
    error err;
    long ic, dc;
    unsigned long line_num;
    char line[LINE_LENGTH],*temp_line, *first_word_in_line, symbol_name[LINE_LENGTH];
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
                if(check_if_syntax_correct(temp_line, &err)) { /* if this line not starts or ends with separator */
                    //todo move entry checking after symbol checking
                    first_word_in_line = str_tok(temp_line, " \t");
                    if (is_entry_def(first_word_in_line)) {
                        check_entry_definition_syntax(line,&err);
                    } else {
                        if (is_symbol_def(first_word_in_line)) { /* if this line starts with symbol */
                            is_symbol = true;
                            pull_symbol_name(first_word_in_line, symbol_name);
                            first_word_in_line = str_tok(NULL," \t");/*first_word_in_line is the first after the symbol definition*/
                            temp_line = temp_line + strlen(symbol_name) + 1;
                            temp_line = trim_whitespace(temp_line);
                        }
                        if ((is_data_def(first_word_in_line) || is_string_def(first_word_in_line))) {
                            int words_num = 0;
                            long first_word_length;
                            first_word_length = strlen(first_word_in_line);
                            if (is_symbol) {
                                add_symbol(symbols, symbol_name, dc, false, false, true, false, &err);
                            }
                            if (is_data_def(first_word_in_line) && err == NOT_ERROR) {
                                check_data_definition_syntax(temp_line, &err);
                                if (err == NOT_ERROR) {
                                    add_data_line(image, dc, temp_line + first_word_length + 1, &words_num, &err);
                                }
                            } else if (is_string_def(first_word_in_line) && err == NOT_ERROR) {
                                check_string_definition_syntax(temp_line, &err);
                                if (err == NOT_ERROR) {
                                    add_string(image, dc, temp_line + first_word_length + 1, &words_num, &err);
                                }
                            }
                            dc += words_num;
                        } else if ((is_extern_def(first_word_in_line))) {
                            int first_word_length;
                            first_word_length = strlen(first_word_in_line);
                            check_extern_definition_syntax(temp_line, &err);
                            if (err == NOT_ERROR) {
                                add_symbol(symbols, temp_line + first_word_length + 1, 0, false, true, false, false,
                                           &err);
                            }
                        } else { /*this line is an instruction.*/
                            instruction temp_instruction;
                            check_instrucion_line_syntax(temp_line, &err);
                            if (err == NOT_ERROR) {
                                if (is_symbol) {
                                    add_symbol(symbols, symbol_name, ic, false, false, false, true, &err);
                                }
                                temp_instruction = init_instruction(temp_line, NULL, ic, &err);
                                ic += get_n_words(temp_instruction);
                                delete_instruction(temp_instruction);
                            }
                        }
                    }
                }
            }
            if(err != NOT_ERROR){
                mark_first_scan_failed(source);
                print_error(line_num, err);
            }
        }

        set_final_dc(source,dc);
        set_final_ic(source,ic-MIN_IC);
        update_addresses(image,ic);
        update_addresses_of_data_symbols(symbols,ic);
        fclose(src);
    }
}

boolean check_if_syntax_correct(char* line, error *err){
    boolean result;
    result = true;

    line = trim_whitespace(line);
    if(line[0] == SEPARATOR){ /* || ((line[strlen(line)]-1) == SEPARATOR)){*/
        *err = ILLEGAL_COMMA;
        result = false;
    }
    return result;
}

void pull_symbol_name(char *first_word, char *dest) {
    strcpy(dest,first_word);
    dest[strlen(first_word)-1]='\0';
}


void check_instrucion_line_syntax(char *line, error *err) {
    check_commas(line, err);
}

void check_extern_definition_syntax(char *line, error *err) {
    if(check_for_comma_in_line(line)){
        *err = ILLEGAL_COMMA;
    }
}

/* check if the first ant last chars are quotation marks */
void check_string_definition_syntax(char *line, error *err) {
    int i=0;
    while(i<strlen(line)-1){
        if(line[i] == '\"'){
            break;
        }
        if(line[i] == SEPARATOR){
            *err = ILLEGAL_COMMA;
        }
        i++;
    }
}

void check_data_definition_syntax(char *line, error *err) {
    check_commas(line, err);
}

void check_symbol_definition_syntax(char *line, error *err) {

}

boolean check_for_comma_in_line(char *line){
    boolean result = false;
    int i=0;

    while ((!result) && i<strlen(line)){
        if (line[i]==SEPARATOR)
            result = true;
        i++;
    }
    return result;
}

/* check if there is commas in this line */
void check_entry_definition_syntax(char *line, error *err) {
    if(check_for_comma_in_line(line)){
        *err = ILLEGAL_COMMA;
    }
}


/**
 * check the validity of the  commas in one line.
 * @param line the input from the user
 * @return OK if the input is ok, detailed information otherwise
 */
void check_commas(char *line, error *err) {
    enum state {BEFORE_OP, AFTER_OP, GETTING_OP, BEFORE_ARG, GETTING_ARG, AFTER_ARG};
    enum state current=BEFORE_OP;
    char tmp_char;
    int i;
    unsigned long length;
    length= strlen(line);
    i=0;

    if(line[length-1]==SEPARATOR){ /* if the line ends with separator */
        *err=ILLEGAL_COMMA;
    }
    while (*err==NOT_ERROR && i<length){
        tmp_char = line[i];
        switch (current){
            case BEFORE_OP:
                if (tmp_char==SEPARATOR){
                    *err= ILLEGAL_COMMA;
                }
                if (!isspace(tmp_char)){
                    current = GETTING_OP;
                }
                break;
            case GETTING_OP:
                if (tmp_char==SEPARATOR){
                    *err= ILLEGAL_COMMA;
                }
                if (isspace(tmp_char)){
                    current=BEFORE_ARG;
                }
                break;
            case BEFORE_ARG:
                if (tmp_char==SEPARATOR){
                    *err= ILLEGAL_COMMA;
                }
                if (!isspace(tmp_char)){
                    current=GETTING_ARG;
                }
                break;
            case GETTING_ARG:
                if (isspace(tmp_char)){
                    current = AFTER_ARG;
                }
                if (tmp_char==SEPARATOR){
                    current = BEFORE_ARG;
                }
                break;
            case AFTER_ARG:
                if (tmp_char==SEPARATOR){
                    current = BEFORE_ARG;
                    break;
                }
                if (!isspace(tmp_char)){
                    *err= MISSING_COMMA;
                }
            default:
                continue;
        }
        i++;
    }
}