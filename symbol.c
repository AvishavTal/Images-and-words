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
    attribute attribute;
};

symbol init_symbol(){
    symbol new_symbol = (symbol)malloc(sizeof(symbol));
    new_symbol->name = NULL;
    new_symbol->value = 0;
    new_symbol->base_address = 0;
    new_symbol->offset = 0;
    new_symbol->attribute = NULL;

    return new_symbol;
}

void update_symbol(symbol symbol, char* name, long value, long base_address, long offset, attribute attribute){
    symbol->name = name;
    symbol->value = value;
    symbol->base_address = base_address;
    symbol->offset = offset;
    symbol->attribute = attribute;
}

char* get_name(symbol symbol){
    printf("in\n");
    printf("%s\n",symbol->name);
    return symbol->name;
}

void set_name(symbol symbol , char *name){
    symbol->name = name;
}


long get_value(symbol symbol){
    printf("value %l", symbol->value);
    return symbol->value;
}

void set_value(symbol symbol , long value){
    symbol->value = value;
}


long get_base_address(symbol symbol){
    return symbol->base_address;
}

void set_base_address(symbol symbol , long base_address){
    symbol->base_address = base_address;
}


long get_offset(symbol symbol){
    return symbol->offset;
}

void set_offset(symbol symbol , long offset){
    symbol->offset = offset;
}


attribute get_attribute(symbol symbol){
    return symbol->attribute;
}

void set_attribute(symbol symbol , attribute attribute){
    symbol->attribute = attribute;
}