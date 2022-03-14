//
// Created by Sapir on 10.3.2022.
//
#include "first_scan.h"

#define MIN_DC 0
#define true 1
#define false 0
#define  NOT_SYMBOL -1

void first_scan(file source) {
    /* variables declaration */
    symbol_table symbols;
    data_image image;
    FILE *src;
    error err;
    long IC, DC;
    int is_there_error, is_symbol, words_num, line_num;
    char line[LINE_LENGTH], *first_word_in_line, *second_word_in_line, *symbol_name;

    /* reset variables */
    err = NOT_ERROR;
    IC = MIN_IC;
    DC = MIN_DC;
    line_num = 0;
    is_there_error = false;// todo mat=ybe need to be share with the second scan
    symbols = get_symbol_table(source);
    image = init_data_image(); /* data image */
    first_word_in_line = get_first_word_in_line(line);
    second_word_in_line = get_first_word_in_line(line + (strlen(first_word_in_line)));
    src = fopen(get_name_am(source), "r");//todo add open file check

    while ((fgets(line, LINE_LENGTH, src)) != NULL) {
        if (!(is_comment(line) || is_empty(line))) { /* if this line is not a blank line or a comment line */
            if (is_syntax_correct) {//todo add the function that check if the commas correct - if everything ok continue
                if (!(is_entry_def(line))) {/* if this line is not an entry line */
                    if (is_symbol_def(first_word_in_line) != NOT_SYMBOL) { /* if this line starts with symbol */
                        is_symbol = true;
                        symbol_name = pull_symbol_name(first_word_in_line);
                    }
                    /* if this line is both symbol and data */
                    if ((is_symbol) && (is_data_def(second_word_in_line))) {
                        add_symbol_seggestion(symbols, symbol_name, DC, false, false, true, false, &err);//todo error maybe error*
                        add_data(image, DC, line + strlen(first_word_in_line) + strlen(second_word_in_line),&words_num);
                        DC += words_num;
                    }
                    /* if this line is data only */
                    else if ((!is_symbol) && (is_data_def(first_word_in_line))) {
                        add_data(image, DC, line + strlen(first_word_in_line), &words_num);//todo maybe to add err
                        DC += words_num;
                    }
                    /* if this line is both symbol and string */
                    else if ((is_symbol) && (is_string_def(second_word_in_line))) {
                        add_symbol_seggestion(symbols, symbol_name, DC, false, false, true, false,&err);//todo error maybe error*
                        add_string(image, DC, line + strlen(first_word_in_line) + strlen(second_word_in_line),
                                   &words_num);//todo maybe to add err
                        DC += words_num;
                    }
                    /* if this line is string only */
                    else if ((!is_symbol) && (is_string_def(first_word_in_line))) {
                        add_string(image, DC, line + strlen(first_word_in_line), &words_num);
                        DC += words_num;
                    }
                    /* if this line is external line */
                    else if (is_extern_def(first_word_in_line)) {
                        add_symbol_seggestion(symbols, line + strlen(first_word_in_line), 0, false, true, false, false,
                                              &err);
                    }
                    /* if this line is both symbol and code */
                    else if (is_symbol) {
                        add_symbol_seggestion(symbols, symbol_name, IC, false, false, false, true,
                                              &err);
                        init_instruction(line + strlen(first_word_in_line), symbols, IC, &words_num, &err);
                        IC += words_num;
                    }
                    /* if this line is code only */
                    else {
                        init_instruction(line + strlen(first_word_in_line), symbols, IC, &words_num, &err);
                        IC += words_num;
                    }
                }
            }
        }
        /* if error was found */
        if(err != NOT_ERROR){
            is_there_error = true;
            print_error(line_num, err);
        }
        line_num ++;
    }
    /* finished the file and there is no errors */
    if(!is_there_error){ // check + print if there is errors - if not continue - exist in file
        ICF = IC;
        DCF = DC;
        update_symbol_table(symbols, ICF, DCF);//todo - im not sure what else is needed
        update_addresses(image, ICF);
    }
}

char* pull_symbol_name(char* str) {
    char *symbol_name = (char*) calloc (1,strlen(str));
    strcpy(symbol_name, str);
    symbol_name = trim_whitespace(symbol_name);
    symbol_name[strlen(symbol_name)-1] = '\0';
    return symbol_name;
}