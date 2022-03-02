//
// Created by avishav on 28.2.2022.
//

#include "macro.h"
#include <stdlib.h>
#define MEM_SIZE 8192
struct macro{
    char *name;
    char **body;
};

macro init_macro(){
    macro new_macro = (macro)malloc(sizeof(struct macro));
    new_macro->name = NULL;
    return new_macro;
}

/*
char *get_symbol_name(macro macro){
    return macro->name;
}
void set_symbol_name(macro macro,char *name){
    macro->name=name;
}

char **get_body(macro macro){
    return macro->body;
}
void set_body(macro macro,char **body){
    macro->body=body;
}*/