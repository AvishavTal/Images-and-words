/*
* Created by Avishav & Sapir on March 9, 2022
*/

#include <string.h>
#include "first_scan.h"
#include "data_image.h"
#include "symbol_table.h"
#include "string_manipulations.h"
#include "instruction.h"
#include "parser.h"
#include "first_and_second_scan_constants.h"
#include "system_errors.h"
#include "boolean.h"

#define MIN_DC 0
#define SEPARATOR ','
#define QUOTATION_MARKS '\"'
#define MAX_LINE_LENGTH 80
#define MEMORY_SIZE 8192

boolean check_if_syntax_correct(char* line, error *err);

void pull_symbol_name(char *first_word, char *dest);

void check_entry_definition_format(char *line, error *err);

void check_symbol_definition_format(char *line, error *err);

void check_data_definition_format(char *line, error *err);

void check_string_definition_format(char *line, error *err);

void check_extern_definition_format(char *line, error *err);

void check_instruction_line_format(char *line, error *err);

void check_commas(char *line, error *err);

boolean check_for_comma_in_line(char *line);

void
encode_data_image_line(data_image image, symbol_table symbols, boolean is_symbol, char *symbol_name,
                       char *first_word_in_line, long *dc, error *err, char *line);

void encode_extern_definition_line(symbol_table symbols, char *line, char *first_word_in_line, error *err);

void
encode_instruction_line(symbol_table symbols, char *symbol_name, boolean is_symbol, char *line, long *ic, error *err);

void scan(file source, FILE *src, symbol_table symbols, data_image image, long *ic, long *dc);

void check_not_start_with_comma(const char *line, error *err);

void check_not_too_long(char *line, error *err);

void memory_check(file source);

void first_scan(file source) {
    /* variables declaration */
    symbol_table symbols;
    data_image image;
    FILE *src;
    long ic, dc;

    /*set variables */
    ic = MIN_IC;
    dc = MIN_DC;
    symbols = get_symbol_table(source);
    image=get_data_image(source);
    src = fopen(get_name_am(source), "r");
    if (!is_open_file_succeeded(src,false, get_name_am(source))){
        mark_first_scan_failed(source);
    } else{
        scan(source, src, symbols, image, &ic, &dc);
        set_final_dc(source,dc);
        set_final_ic(source,ic-MIN_IC);
        memory_check(source);
        update_addresses(image,ic);
        update_addresses_of_data_symbols(symbols,ic);
        fclose(src);
    }
}

void memory_check(file source) {
    unsigned long ic,dc,total;
    ic=get_final_ic(source);
    dc=get_final_dc(source);
    total=ic+dc;
    if (total>MEMORY_SIZE){
        print_error(0,MEMORY_OVERFLOW);
        mark_first_scan_failed(source);
    }
}

void scan(file source, FILE *src, symbol_table symbols, data_image image, long *ic, long *dc) {
    char line[LINE_LENGTH],*temp_line, *first_word_in_line, symbol_name[LINE_LENGTH];
    unsigned long line_num;
    boolean is_symbol;
    error err;
    line_num = 0;
    while ((fgets(line, LINE_LENGTH, src)) != NULL) {
        is_symbol=false;
        err = NOT_ERROR;
        line_num ++;
        temp_line= trim_whitespace(line);
        if (!(is_comment(line) || is_empty(line))) {
            if(check_if_syntax_correct(temp_line, &err)) {
                first_word_in_line = str_tok(temp_line, " \t");
                if (is_symbol_def(first_word_in_line)) {
                    is_symbol = true;
                    pull_symbol_name(first_word_in_line, symbol_name);
                    first_word_in_line = str_tok(NULL," \t");/*first_word_in_line is the first after the symbol definition*/
                    temp_line = temp_line + strlen(symbol_name) + 1;
                    temp_line = trim_whitespace(temp_line);
                }
                if (first_word_in_line!=NULL){
                    if (is_entry_def(first_word_in_line)) {
                        check_entry_definition_format(line, &err);
                    } else if ((is_data_def(first_word_in_line) || is_string_def(first_word_in_line))) {
                        encode_data_image_line(image, symbols, is_symbol, symbol_name, first_word_in_line, dc, &err, temp_line);
                    } else if ((is_extern_def(first_word_in_line))) {
                        encode_extern_definition_line(symbols,temp_line,first_word_in_line,&err);
                    } else { /*this line is an instruction.*/
                        encode_instruction_line(symbols, symbol_name, is_symbol, temp_line, ic, &err);
                    }
                }
            }
        }
        if(err != NOT_ERROR){
            mark_first_scan_failed(source);
            print_error(line_num, err);
        }
    }
}

void
encode_instruction_line(symbol_table symbols, char *symbol_name, boolean is_symbol, char *line, long *ic, error *err) {
    instruction temp_instruction;
    check_instruction_line_format(line, err);
    if (*err == NOT_ERROR) {
        if (is_symbol) {
            add_symbol(symbols, symbol_name, *ic, false, false, false, true, err);
        }
        temp_instruction = init_instruction(line,NULL,*ic,err);
        (*ic) += get_n_words(temp_instruction);
        delete_instruction(temp_instruction);
    }
}

void encode_extern_definition_line(symbol_table symbols, char *line, char *first_word_in_line, error *err) {
    int first_word_length;
    first_word_length = strlen(first_word_in_line);
    check_extern_definition_format(line, err);
    if (*err == NOT_ERROR && strcmp(first_word_in_line,line)) {/*valid syntax and the line contains more than one word*/
        add_symbol(symbols, line + first_word_length + 1, 0, false, true, false, false,err);
    }
}

void
encode_data_image_line(data_image image, symbol_table symbols, boolean is_symbol, char *symbol_name,
                       char *first_word_in_line, long *dc, error *err, char *line) {
    int words_num = 0;
    long first_word_length;
    first_word_length = strlen(first_word_in_line);
    if (is_symbol) {
        add_symbol(symbols, symbol_name, *dc, false, false, true, false, err);
    }
    if (is_data_def(first_word_in_line) && *err == NOT_ERROR) {
        check_data_definition_format(line, err);
        if (*err == NOT_ERROR) {
            add_data_line(image, *dc, line + first_word_length + 1, &words_num, err);
        }
    } else if (is_string_def(first_word_in_line) && *err == NOT_ERROR) {
        check_string_definition_format(line, err);
        if (*err == NOT_ERROR) {
            add_string(image, *dc, line + first_word_length + 1, &words_num, err);
        }
    }
    (*dc) += words_num;
}


boolean check_if_syntax_correct(char* line, error *err){
    boolean result;
    result = true;
    line = trim_whitespace(line);
    check_not_too_long(line,err);
    check_not_start_with_comma(line,err);
    if (*err!=NOT_ERROR){
        result=false;
    }
    return result;
}

void check_not_too_long(char *line, error *err) {
    if (number_of_not_spaces_chars(line)>MAX_LINE_LENGTH){
        *err=TOO_LONG_LINE;
    }
}

void check_not_start_with_comma(const char *line, error *err) {
    if(line[0] == SEPARATOR){
        *err = ILLEGAL_COMMA;
    }
}

void pull_symbol_name(char *first_word, char *dest) {
    strcpy(dest,first_word);
    dest[strlen(first_word)-1]='\0';
}


void check_instruction_line_format(char *line, error *err) {
    check_commas(line, err);
}

void check_extern_definition_format(char *line, error *err) {
    if(check_for_comma_in_line(line)){
        *err = ILLEGAL_COMMA;
    }
}

/* check if the first ant last chars are quotation marks */
void check_string_definition_format(char *line, error *err) {
    int i = 0;
    char* temp;
    temp = str_tok(line, " \t");
    temp = str_tok(NULL, " \t");
    if(temp == NULL){
        *err = STRING_NOT_EXIST;
    }
    while(i<strlen(line)-1){
        if(line[i] == QUOTATION_MARKS){
            break;
        }
        if(line[i] == SEPARATOR){
            *err = ILLEGAL_COMMA;
        }
        i++;
    }
}

void check_data_definition_format(char *line, error *err) {
    char* temp;
    temp = str_tok(line, " \t");
    temp = str_tok(NULL, " \t");
    if(temp == NULL){
        *err = DATA_NOT_EXIST;
    }
    check_commas(line, err);
}

void check_symbol_definition_format(char *line, error *err) {

}

/* check if there is commas in this line */
void check_entry_definition_format(char *line, error *err) {
    if(check_for_comma_in_line(line)){
        *err = ILLEGAL_COMMA;
    }
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