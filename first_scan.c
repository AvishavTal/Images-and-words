//
// Created by avishav on 28.2.2022.
//
#include <stdio.h>
#include <string.h>
#include "first_scan.h"
#include "symbol_table.h"
#include "string_manipulations.h"
#include "symbol.h"
#include "file.h"
#include "instruction.h"
#include "parser.h"
#include "first_and_second_scan_constants.h"

#define MIN_DC 0
#define true 1
#define false 0
#define  NOT_SYMBOL -1

int check_if_label(char *first_word_in_line);//todo exist in parser.h (is_symbol_def)

int get_base_address(int address){

}
void add_data_or_string_label_to_symbol_table(symbol_table symbol_table,char *label_name, int DC ){
    long base_address = (int)(140/16) * 16;
    long offset = DC - base_address;

    add_symbol(symbol_table, label_name, DC, base_address, offset, false, false, true, false,error *error1);//todo error, how to update DC
}
int add_data_or_string_to_data_image(data_image data_image, /*......*/ ){

}


void first_scan(file source) {
    symbol_table symbols;
    data_image image;
    char line[LINE_LENGTH];
    char *first_word_in_line  = get_first_word_in_line(line);
    char *second_word_in_line = get_first_word_in_line(line + (strlen(first_word_in_line)));
    FILE *src, *dest;
    int IC = MIN_IC, DC = MIN_DC;
    int is_there_error = false;
    int is_symbol;
    char *label_name;
    int chars_num; /* num of chars with whitespaces up to the end of the word */

    first_word_in_line  = trim_whitespace(first_word_in_line);
    second_word_in_line = trim_whitespace(second_word_in_line);

    symbols = get_symbol_table(source);
    image = init_data_image(); /* data image */

    src= fopen(get_name_am(source),"r");//todo add open file check
    dest= fopen(get_name_ob(source),"a");

    while ((fgets(line,LINE_LENGTH,src))!=NULL){
        if(!(is_comment(line) || is_empty(line))){ /* if this line is not a blank line or a comment line */
            if(is_syntax_correct) {//todo add the function that check if the commas correct - if everything ok continue
                if(!(is_entry_def(line))){/* if this line is not an entry line */
                    if(is_symbol_def(line) != NOT_SYMBOL){ /* if this line starts with symbol */
                        is_symbol = true;
                    }
                    if((is_symbol) && (is_data_def(second_word_in_line))){ /* if this line is both symbol and data */

                    }
                    else if((!is_symbol) && (first_word_in_line)) { /* if this line is data only */

                    }

                    if(is_string_def(line)) {//todo

                    }
                    if(is_extern_def(line)) {//todo

                    }
                    if(is_code_symbol(line)) {

                    }


                }
            }
        }
    }






        //* todo not ignor from entry and hen check comma - if not error check entry *//
        /* If this line is a blank line or a comment line or entry*/
        //if(!(first_word_in_line == NULL || first_word_in_line == COMMENT_DELIMITERS || is_entry_def(first_word_in_line)){ //todo use parser functions
            //if(check_if_label(first_word_in_line)){//todo -use function in parser
               // is_label = true;
                strcpy(label_name, strtok(first_word_in_line,":")); /* label_name will be the name witout the : */ // todo put in string manipulation

                /* if both label and data */
                if(is_string_def(second_word_in_line) || is_data_def(second_word_in_line)) {
                    add_data_or_string_label_to_symbol_table(symbols, label_name, DC );
                    DC += add_data_or_string_to_data_image();//todo, void add_data(char *line, int dc, error *error);void add_string(char *line, int dc, error *error)
                }
                //todo add if instruction with label
            }
            else { /* if not label */
                /* if data or string line*/
                if (is_string_def(first_word_in_line) || is_data_def(first_word_in_line)) {
                    DC += add_data_or_string_to_data_image();
                }
                /* if external line */
                else if (is_extern_def(first_word_in_line)) {
                    add_symbol(symbols, second_word_in_line, 0, 0,
                               0, false, true, false, false,error *error1);//todo error
                }
                /* its instraction line */
                else {
                    if (is_label) {
                        add_code_label_to_symbol_table(symbols, label_name, IC);
                    }
                    //todo add instuction and check errors - init_instruction, add variable to sent - how many lines does it take
                    IC += add_instraction(); // inside the func check if the instraction name exist, check if operand num correct and if the miun(?) type correct
                }
            }
        }
        //todo update line counter
    } /* We have completed the transition over the entire file  */

    if(!(print_errors())){ // check + print if there is errors - if not continue - exist in file
        ICF = IC;
        DCF = DC;
        update_symbol_table(ICF);//todo
        update_addresses(image, ICF);
    }

}



/*
void second_scan(file source){

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
*/