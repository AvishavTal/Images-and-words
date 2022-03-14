//
// Created by avishav on 10.3.2022.
//

#include "parser.h"
#include "string_manipulations.h"
#include <string.h>
#include "boolean.h"

#define END_OF_LABLE_SIGN ':'
#define START_OF_COMMENT ';'
#define STRING_BOUNDARY '\"'

int is_entry_def(char *str) {
    return !strcmp(str,".entry");
}

int is_data_def(char *str) {
    return !strcmp(str,".data");
}

int is_string_def(char *str) {
    return !strcmp(str,".string");
}

int is_extern_def(char *str) {
    return !strcmp(str,".extern");
}


int is_symbol_def(char *line) {
    int result = -1;
    char *first_word_in_line = get_first_word_in_line(line);
    if(first_word_in_line[strlen(first_word_in_line)-1] == ':'){
        result = true;
    }
    return result;
}

int is_comment(char *line){
    trim_whitespace(line);
    return *line==START_OF_COMMENT;
}

int is_empty(char *line){
    unsigned long len;
    len= strlen(line);
    while (len>0){
        if (!isspace(line[--len])){
            return 0;
        }
    }
    return 1;
}

/* if this str is string - i.e start and end with quotation marks "" */
int is_string(char *line){
    unsigned long len;
    len= strlen(line);
    return line[0]==STRING_BOUNDARY&&line[len-1]==STRING_BOUNDARY;
}


