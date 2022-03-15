/*
* Created by Avishav & Sapir on March 10,2022
*/

#include <string.h>
#include "parser.h"
#include "string_manipulations.h"
#include "boolean.h"
#include "operator_table.h"
#include "register_table.h"

#define END_OF_SYMBOL_SIGN ':'
#define START_OF_COMMENT ';'
#define STRING_BOUNDARY '\"'

boolean is_entry_def(char *word) {
    word=trim_whitespace(word);
    return !strcmp(word,".entry");
}

boolean is_data_def(char *word) {
    word=trim_whitespace(word);
    return !strcmp(word,".data");
}

boolean is_string_def(char *word) {
    word=trim_whitespace(word);
    return !strcmp(word,".string");
}

boolean is_extern_def(char *word) {
    word=trim_whitespace(word);
    return !strcmp(word,".extern");
}

boolean is_symbol_def(char *word) {
    word=trim_whitespace(word);
    return *(word+ strlen(word)-1) == END_OF_SYMBOL_SIGN;
}

boolean is_comment(char *line){
    line=trim_whitespace(line);
    return *line==START_OF_COMMENT;
}

boolean is_empty(char *line){
    unsigned long len;
    len= strlen(line);
    while (len>0)
        if (!isspace(line[--len]))
            return false;
    return true;
}

boolean is_string(char *line){
    line=trim_whitespace(line);
    return line[0]==STRING_BOUNDARY&&line[strlen(line)-1]==STRING_BOUNDARY;
}

boolean is_reserved_word(char *word){
    word= trim_whitespace(word);
    return ((get_register_by_name(word)!=NULL) || (get_operator_by_name(word) != NULL) || is_entry_def(word) ||
            is_data_def(word) || is_extern_def(word) || is_string_def(word));
}