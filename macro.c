//
// Created by Sapir on 28.2.2022.
//

#include "macro.h"
#include "linked_list.h"
#include <stdlib.h>
#include "string_manipulations.h"
#define MEM_SIZE 8192
struct macro{
    char *name; //maybe todo with string of 31 chars - than no need to free - if so to change in set_macro_name
    list body; //maybe todo in array with define constant number - than no need to free - if so to change in init_macro and set_macro_body
};

/* create new macro and reset all variables */
macro init_macro(){
    macro new_macro = (macro)malloc(sizeof(struct macro));
    new_macro->name = NULL;
    new_macro->body = create_empty_list();
    return new_macro;
}

char *get_macro_name(macro macro){
    return macro->name;
}
void set_macro_name(macro macro, char *name){
    trim_whitespace(name);
    macro->name=(char *) malloc(strlen(name)+1);
    strcpy(macro->name,name);
}

list get_macro_body(macro macro){
    return macro->body;
}
void set_macro_body(macro macro, list body){
    macro->body=body;
}

/*append line to the body of the macro - add new instruction*/
void append_line(macro macro, char *line){
    char *new_line=(char *) malloc(strlen(line)+1);
    strcpy(new_line,line);
    add_to_tail(macro->body,new_line);
}

/*
char *next_line(macro macro){
    static node current;
    char *result=NULL;
    current= get_head(macro->body);
    if (current){
        result= get_node_data(current);
        current= get_next_node(current);
    }
    return "";
}
*/

//Consider whether or not to delete - by the allocation type - if not delete change the function
void free_macro(macro macro){
    free(macro->name);
    free(macro->body);
}

