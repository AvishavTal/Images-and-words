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
    macro result=(macro)malloc(sizeof(struct macro));
    result->name=NULL;
    return result;
}

char **get_body(macro macro){
    return macro->body;
}
char *get_name(macro macro){
    return macro->name;
}
void set_name(macro macro,char *name){
    macro->name=name;
}
void set_body(macro macro,char **body){
    macro->body=body;
}