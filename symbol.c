//
// Created by Sapir on 28.2.2022.
//
#include <stdlib.h>
#include<stdio.h>

#include "symbol.h"

struct symbol{
    char *name;
    long value;
    long base_address;
    long offset;
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

/* update the variables of given symbol*/
void update_symbol(symbol symbol, char* name, long value, long base_address, long offset){
    symbol->name = name;
    symbol->value = value;
    symbol->base_address = base_address;
    symbol->offset = offset;
//    symbol->attribute = attribute;
}

char* get_symbol_name(symbol symbol){
    return symbol->name;
}
void set_symbol_name(symbol symbol , char *name){
    symbol->name = name;
}

long get_symbol_value(symbol symbol){
    printf("value %l", symbol->value);//todo ???
    return symbol->value;
}
void set_symbol_value(symbol symbol , long value){
    symbol->value = value;
}

long get_symbol_base_address(symbol symbol){
    return symbol->base_address;
}
void set_symbol_base_address(symbol symbol , long base_address){
    symbol->base_address = base_address;
}

long get_symbol_offset(symbol symbol){
    return symbol->offset;
}
void set_symbol_offset(symbol symbol , long offset){
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
//todo free symbol
