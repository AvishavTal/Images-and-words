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

boolean is_entry_def(char *str) {
    return !strcmp(str,".entry");
}

boolean is_data_def(char *str) {
    return !strcmp(str,".data");
}

boolean is_string_def(char *str) {
    return !strcmp(str,".string");
}

boolean is_extern_def(char *str) {
    return !strcmp(str,".extern");
}

boolean is_symbol_def(char *str) {
    char last_char=*(str+ strlen(str)-1);
    return last_char==END_OF_LABLE_SIGN;
}

boolean is_comment(char *line){
    char *temp;
    temp=trim_whitespace(line);
    return *temp==START_OF_COMMENT;
}

boolean is_empty(char *line){
    unsigned long len;
    len= strlen(line);
    while (len>0) {
        if (!isspace(line[--len])) {
            return false;
        }
    }
    return true;
}

boolean is_string(char *line){
    char *temp;
    unsigned long len;
    temp=trim_whitespace(line); // todo think if need to remove spaces from the end of the line
    len= strlen(temp);
    return line[0]==STRING_BOUNDARY&&line[len-1]==STRING_BOUNDARY;
}