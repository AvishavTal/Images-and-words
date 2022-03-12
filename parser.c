//
// Created by avishav on 10.3.2022.
//

#include "parser.h"
#include "string_manipulations.h"
#include <string.h>

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
/**
 * get line and check if start with a label definition
 * @param str line to check
 * @return length of label if exist, -1 otherwise
 */
int is_symbol_def(char *str) {
    int symbol_length=0,is_symbol=0,result=-1;
    while (*str!='\0'&&!is_symbol){
        if(*str==END_OF_LABLE_SIGN){
            is_symbol=1;
        }
        symbol_length++;
        str++;
    }
    if(is_symbol){
        result=symbol_length;
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

int is_string(char *line){
    unsigned long len;
    len= strlen(line);
    return line[0]==STRING_BOUNDARY&&line[len-1]==STRING_BOUNDARY;
}


