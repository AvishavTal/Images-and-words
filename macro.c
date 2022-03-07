//
// Created by Sapir on 28.2.2022.
//

#include "macro.h"
#include "linked_list.h"
#include <stdlib.h>
#define MEM_SIZE 8192
struct macro{
    char *name;
    list body; //maybe todo in array be define number
};

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
    macro->name=name;
}

list get_macro_body(macro macro){
    return macro->body;
}
void set_macro_body(macro macro, list body){
    macro->body=body;
}

//todo free macro


