//
// Created by Sapir on 28.2.2022.
//
#include <stdlib.h>
#include<stdio.h>
#include <string.h>

#include "symbol.h"

struct symbol{
    char *name;
    unsigned long value;
    unsigned long base_address;
    unsigned long offset;
    struct attr{
        unsigned int is_entry :1;
        unsigned int is_extern :1;
        unsigned int is_data :1;
        unsigned int is_code :1;
    }attribute;
};

/* create new symbol and reset all variables */
symbol init_symbol(){
    symbol new_symbol = (symbol)malloc(sizeof(struct symbol));
    new_symbol->name = NULL;
    new_symbol->value = 0;
    new_symbol->base_address = 0;
    new_symbol->offset = 0;
    new_symbol->attribute.is_extern=0;
    new_symbol->attribute.is_entry=0;
    new_symbol->attribute.is_data=0;
    new_symbol->attribute.is_code=0;
    return new_symbol;
}

symbol init_symbol_with_values(char *name, unsigned long value, unsigned long base_address, unsigned long offset, int is_entry, int is_extern, int is_data, int is_code){
    symbol new_symbol = (symbol)malloc(sizeof(struct symbol));
    new_symbol->name = name;
    new_symbol->value = value;
    new_symbol->base_address = base_address;
    new_symbol->offset = offset;
    new_symbol->attribute.is_extern=is_extern;
    new_symbol->attribute.is_entry=is_entry;
    new_symbol->attribute.is_data=is_data;
    new_symbol->attribute.is_code=is_code;
    return new_symbol;
}


/* update the variables of given symbol*/
void update_symbol(symbol symbol, char* name, unsigned long value, unsigned long base_address, unsigned long offset){
    set_symbol_name(symbol,name);
    set_symbol_value(symbol,value);
    set_symbol_base_address(symbol,base_address);
    set_symbol_offset(symbol,offset);
}


char* get_symbol_name(symbol symbol){
    return symbol->name;
}
void set_symbol_name(symbol symbol , char *name){
    char *new_name;
    new_name=(char *) malloc(strlen(name)+1);
    strcpy(new_name,name);
    symbol->name = name;
}

unsigned long get_symbol_value(symbol symbol){
    return symbol->value;
}
void set_symbol_value(symbol symbol , unsigned long value){
    symbol->value = value;
}

unsigned long get_symbol_base_address(symbol symbol){
    return symbol->base_address;
}
void set_symbol_base_address(symbol symbol , unsigned long base_address){
    symbol->base_address = base_address;
}

unsigned long get_symbol_offset(symbol symbol){
    return symbol->offset;
}
void set_symbol_offset(symbol symbol , unsigned long offset){
    symbol->offset = offset;
}
void mark_entry(symbol to_mark){
    to_mark->attribute.is_entry=1;
}
void mark_extern(symbol to_mark){
    to_mark->attribute.is_extern=1;
}
void mark_code(symbol to_mark){
    to_mark->attribute.is_code=1;
}
void mark_data(symbol to_mark){
    to_mark->attribute.is_data=1;
}
int is_entry_symbol(symbol symba){
    return symba->attribute.is_entry;
}
int is_extern_symbol(symbol symba){
    return symba->attribute.is_extern;
}
int is_code_symbol(symbol symba){
    return symba->attribute.is_code;
}
int is_data_symbol(symbol symba){
    return symba->attribute.is_data;
}
/*
attribute get_symbol_attribute(symbol symbol){
    return symbol->attribute;
}
void set_symbol_attribute(symbol symbol , attribute attribute){
    symbol->attribute = attribute;
}
*/
void delete_symbol(symbol to_delete){
    free(to_delete->name);
    free(to_delete);
}
