//
// Created by avishav on 10.3.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro_body.h"
#include "linked_list.h"

struct body{
    list lines;
};
macro_body init_body(){
    macro_body result;
    result=(macro_body) malloc(sizeof(struct body));
    result->lines=create_empty_list();
    return result;
}

void delete_body(macro_body to_delete){
    node current;
    current= get_head(to_delete->lines);
    while (current!=NULL){
        free(get_node_data(current));
        current= get_next_node(current);
    }
    free_list(to_delete->lines);
    free(to_delete);
}

void append_line_to_body(macro_body to_update,char *line){
    char *new_line;
    unsigned long len;
    len=strlen(line)+1;
    new_line=(char *) malloc(len);
    strcpy(new_line, line);
    add_to_tail(to_update->lines, new_line);
}

void print_body(FILE *dest, macro_body to_print) {
    node current;
    current= get_head(to_print->lines);
    while (current){
        fprintf(dest,"%s",(char *) get_node_data(current));
        current= get_next_node(current);
    }
}
