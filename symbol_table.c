/*
* Created by Avishav & Sapir on March 7, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbol_table.h"
#include "linked_list.h"
#include "parser.h"
#include "string_manipulations.h"
#include "boolean.h"
#include "errors.h"
#include "system_errors.h"

#define BASE 16
#define MAX_NAME_LENGTH 31

struct symbol_table{
    list table;
};

/* Internal function declaration */
void push_symbol(symbol_table to_update,symbol to_push);
boolean double_definition(symbol_table symbols, char *name, boolean is_extern, error *err);
boolean is_legal_name(char *name);


symbol_table init_symbol_table(){
    symbol_table result;
    result=NULL;
    result=(symbol_table)malloc(sizeof(struct symbol_table));
    if(is_allocation_succeeded(result)){
        result->table = create_empty_list();
    }
    return result;
}

void add_symbol(symbol_table symbols, char *symbol_name, unsigned long address, boolean is_entry, boolean is_extern,
                boolean is_data, boolean is_code, error *err){
    if (!is_legal_name(symbol_name)){
        *err=ILLEGAL_SYMBOL_NAME;
    } else if(!double_definition(symbols, symbol_name, is_extern, err)){
        symbol new_symbol;
        new_symbol=NULL;
        new_symbol= init_symbol_with_values(symbol_name, address, is_entry, is_extern, is_data, is_code);
        push_symbol(symbols,new_symbol);
    }
}

symbol get_symbol_by_name(symbol_table symbols, char *symbol_name){
    node current_node;
    current_node=NULL;
    symbol_name= trim_whitespace(symbol_name);
    current_node= get_head(symbols->table);
    while (current_node){
        symbol current_symbol;
        current_symbol=NULL;
        current_symbol=get_node_data(current_node);
        if(!strcmp(symbol_name, get_symbol_name(current_symbol))){
            return current_symbol;
        }
        current_node= get_next_node(current_node);
    }
    return NULL;
}

void delete_symbol_table(symbol_table to_delete){
    node current;
    current=NULL;
    current = get_head(to_delete->table);
    while (current){
        delete_symbol((symbol)get_node_data(current));
        current=get_next_node(current);
    }
    free_list(to_delete->table);
    free(to_delete);
}

void print_entries(FILE *dest,symbol_table to_print){
    node current_node;
    symbol current_symbol;
    current_node=NULL;
    current_symbol=NULL;
    current_node= get_head(to_print->table);
    while (current_node){
        current_symbol=get_node_data(current_node);
        if (get_is_entry_symbol(current_symbol)){
            print_entry_symbol(dest,current_symbol);
        }
        current_node=get_next_node(current_node);
    }
}

void print_externals(FILE *dest,symbol_table to_print){
    node current_node;
    symbol current_symbol;
    current_node=NULL;
    current_symbol=NULL;
    current_node= get_head(to_print->table);
    while (current_node){
        current_symbol=get_node_data(current_node);
        if (get_is_extern_symbol(current_symbol)){
            print_extern_symbol(dest,current_symbol);
        }
        current_node=get_next_node(current_node);
    }
}

void update_addresses_of_data_symbols(symbol_table symbols,unsigned long final_ic){
    node current_node;
    symbol current_symbol;
    current_node=NULL;
    current_symbol=NULL;
    current_node= get_head(symbols->table);
    while (current_node){
        current_symbol=get_node_data(current_node);
        if (get_is_data_symbol(current_symbol)){
            unsigned long address;
            address= get_symbol_address(current_symbol);
            address+=final_ic;
            set_symbol_address(current_symbol, address);
        }
        current_node=get_next_node(current_node);
    }
}

/* Internal function - this function gets legal symbol name and push it to the table*/
void push_symbol(symbol_table to_update,symbol to_push){
    add_to_tail(to_update->table,to_push);
}

/* Internal function - this function gets symbol table, name of symbol, flag if this symbol is extern and option to error
 * check if this symbol name already exist in the table without extern definition
 * return true if already exist, false otherwise*/
boolean double_definition(symbol_table symbols, char *name, boolean is_extern, error *err){
    boolean result;
    symbol old_symbol;
    result = false;
    old_symbol=NULL;
    old_symbol= get_symbol_by_name(symbols,name);
    if(old_symbol!=NULL){
        if (!(get_is_extern_symbol(old_symbol) && is_extern)){
            *err=DOUBLE_DEFINITION_OF_SYMBOL;
        }
        result = true;
    }

    return result;
}

/* Internal function - this function gets name of symbol
 * check if this name is legal,e.g. not reserved word, no longer than allowed, starts with alpha letter, all the characters are alphanumeric
 * return true if the received name is legal name, false otherwise*/
boolean is_legal_name(char *name){
    boolean result;
    result=true;
    if(is_reserved_word(name)|| (strlen(name)>MAX_NAME_LENGTH)||!isalpha(*name)||!is_alpha_numeric_word(name)){
        result=false;
    }
    return result;
}