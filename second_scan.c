//
// Created by avishav on 28.2.2022.
//
#include <stdio.h>
#include <string.h>
#include "second_scan.h"
#include "symbol_table.h"
#include "string_manipulations.h"
#define LINE_LENGTH 81

#define END_OF_LABLE_SIGN ':'

int is_symbol(char *str);

int is_extern(char *str);

int is_string(char *str);


int is_data(char *str);

int is_entry(char *str);

void second_scan(file source){
    symbol_table table;
    char line[LINE_LENGTH],*first_word_in_line;
    FILE *src,*dest;
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
                //todo 5
            } else{
                //todo 6
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
