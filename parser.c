//
// Created by avishav on 10.3.2022.
//

#include "parser.h"
#include "string_manipulations.h"
#include <string.h>

#define END_OF_LABLE_SIGN ':'
#define START_OF_COMMENT ';'

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

int is_symbol_def(char *str) { //todo get the whole line and return if this line start with label (check up to :)
    char last_char=*(str+ strlen(str)-1);
    return last_char==END_OF_LABLE_SIGN;
}

int is_comment(char *line){
    trim_whitespace(line);
    return *line==START_OF_COMMENT;
}

//todo is empty
