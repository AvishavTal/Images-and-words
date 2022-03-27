/*
** Created by Avishav & Sapir on March 1,2022
*/

#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "boolean.h"
#include "system_errors.h"

#define BASE 16

struct symbol{
    char *name;
    unsigned long address;
    struct attr{
        boolean is_entry :1;
        boolean is_extern :1;
        boolean is_data :1;
        boolean is_code :1;
    }attribute;
};

symbol init_symbol(){
    symbol new_symbol;
    new_symbol=(symbol)calloc(1,sizeof(struct symbol));
    if(is_allocation_succeeded(new_symbol)) {
        new_symbol->name = NULL;
        new_symbol->address = 0;
        new_symbol->attribute.is_entry = false;
        new_symbol->attribute.is_extern = false;
        new_symbol->attribute.is_data = false;
        new_symbol->attribute.is_code = false;
    }
    return new_symbol;
}

symbol init_symbol_with_values(char *name, unsigned long address, boolean is_entry, boolean is_extern, boolean is_data, boolean is_code){
    symbol new_symbol;
    new_symbol=(symbol)malloc(sizeof(struct symbol));
    if(is_allocation_succeeded(new_symbol)) {
        set_symbol_name(new_symbol,name);
        new_symbol->address = address;
        new_symbol->attribute.is_entry = is_entry;
        new_symbol->attribute.is_extern = is_extern;
        new_symbol->attribute.is_data = is_data;
        new_symbol->attribute.is_code = is_code;
    }
    return new_symbol;
}

void update_symbol(symbol curr_symbol, char* name, unsigned long address){
    set_symbol_name(curr_symbol,name);
    set_symbol_address(curr_symbol, address);
}

char* get_symbol_name(symbol curr_symbol){
    return curr_symbol->name;
}

void set_symbol_name(symbol curr_symbol , char *name){
    char *new_name;
    new_name=(char *) malloc(strlen(name)+1);
    if(is_allocation_succeeded(new_name)) {
        strcpy(new_name, name);
        curr_symbol->name = new_name;
    }
}

unsigned long get_symbol_address(symbol curr_symbol){
    return curr_symbol->address;
}

void set_symbol_address(symbol curr_symbol , unsigned long address){
    curr_symbol->address=address;
}

unsigned long get_symbol_base_address(symbol curr_symbol){
    return (curr_symbol->address / BASE)*BASE;
}

unsigned long get_symbol_offset(symbol curr_symbol){
    return curr_symbol->address % BASE;
}

void mark_entry(symbol to_mark){
    to_mark->attribute.is_entry = true;
}

void mark_extern(symbol to_mark){
    to_mark->attribute.is_extern = true;
}

void mark_code(symbol to_mark){
    to_mark->attribute.is_code = true;
}

void mark_data(symbol to_mark){
    to_mark->attribute.is_data = true;
}

boolean get_is_entry_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_entry;
}

boolean get_is_extern_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_extern;
}

boolean get_is_code_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_code;
}

boolean get_is_data_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_data;
}

void delete_symbol(symbol to_delete){
    free(to_delete->name);
    free(to_delete);
}