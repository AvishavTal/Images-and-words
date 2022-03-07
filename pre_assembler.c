//
// Created by avishav on 2.3.2022.
//
#include <stdio.h>
#include <string.h>
#include "string_manipulations.h"
#include "macro_table.h"
#include "file.h"

#define LINE_SIZE 81

void write_macro_content(FILE *dest, macro to_write);
int start_of_macro_definition(char *first_word);
int end_of_macro_definition(char *line);
void write_line(FILE *dest, char *line);

void pre_assembler(file source) {
    FILE *src,*dest;
    int macro_definition=0;
    char line[LINE_SIZE],temp_line[LINE_SIZE],*first_word_in_line;
    macro temp_macro;
    macro_table table= get_macro_table(source);
    src= fopen(get_name_as(source),"r");//todo check if open file succeeded
    dest= fopen(get_name_am(source),"a");

    while ((fgets(line,LINE_SIZE,src)!=NULL)){
        strcpy(temp_line,line);
        first_word_in_line= strtok(temp_line," \t");//todo \n
        trim_whitespace(first_word_in_line);
        if(!macro_definition){
            if((temp_macro= get_macro_by_name(table, first_word_in_line)) != NULL){/*macro call*/
                write_macro_content(dest,temp_macro);
            } else if(start_of_macro_definition(first_word_in_line)){
                char *name;
                temp_macro=init_macro();
                macro_definition=1;
                name= strtok(NULL," \t");
                set_macro_name(temp_macro, name);
            } else{
                write_line(dest,line);
            }
        } else{
            if(end_of_macro_definition(first_word_in_line)){
                push_macro(table, temp_macro);
                macro_definition=0;
            } else{
                append_line(temp_macro,line);
            }
        }
    }
}

void write_line(FILE *dest, char *line) {
    fprintf(dest,"%s",line);
}

int end_of_macro_definition(char *line) {
    return !strcmp(line,"endm");
}

int start_of_macro_definition(char *first_word) {
    return !strcmp(first_word,"macro");
}

void write_macro_content(FILE *dest, macro to_write) {
    node current= get_head(get_macro_body(to_write));
    while (current){
        fprintf(dest,"%s", (char *)get_node_data(current));
        current= get_next_node(current);
    }
}
