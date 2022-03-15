//
// Created by avishav on 7.3.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "linked_list.h"
#include "parser.h"
#include "string_manipulations.h"
#include "boolean.h"


#define BASE 16

#define MAX_NAME_LENGTH 31


struct symbol_table{
    list table;
};


int is_legal_name(char *name);

int double_definition(symbol_table symbols, char *name, int is_extern, error *error1);

symbol_table init_symbol_table(){
    symbol_table result;
    result=(symbol_table)malloc(sizeof(struct symbol_table));
    result->table=create_empty_list();
    return result;
}

void add_symbol(symbol_table symbols, char *symbol_name, unsigned long address, int is_entry,
                int is_extern, int is_data, int is_code, error *error1){
    if (!is_legal_name(symbol_name)){
        *error1=ILLEGAL_SYMBOL_NAME;
    } else if(double_definition(symbols, symbol_name, is_extern, error1)){
        symbol new_symbol;
        new_symbol= init_symbol_with_values(symbol_name, address, is_entry, is_extern, is_data, is_code);
        push_symbol(symbols,new_symbol);
    }
}

symbol get_symbol_by_name(symbol_table symbols, char *symbol_name) {
    node current_node=NULL;
    current_node= get_head(symbols->table);
    while (current_node){
        symbol current_symbol=get_node_data(current_node);
        if(!strcmp(symbol_name, get_symbol_name(current_symbol))){
            return current_symbol;
        }
        current_node= get_next_node(current_node);
    }
    return NULL;
}

void push_symbol(symbol_table to_update,symbol to_push){
    add_to_tail(to_update->table,to_push);
}


void delete_symbol_table(symbol_table to_delete){
    node current;
    current = get_head(to_delete->table);
    while (current){
        delete_symbol((symbol)get_node_data(current));
        current=get_next_node(current);
    }
}

void print_entries(FILE *dest,symbol_table to_print){
    node current_node;
    symbol current_symbol=NULL;
    current_node= get_head(to_print->table);
    while (current_node){
        current_symbol=get_node_data(current_node);
        if (is_entry_symbol(current_symbol)){
            char *name;
            unsigned long address,offset;
            name= get_symbol_name(current_symbol);
            address= get_symbol_base_address(current_symbol);
            offset= get_symbol_offset(current_symbol);
            fprintf(dest,"%s,%04ld,%04ld\n",name,address,offset);
        }
        current_node=get_next_node(current_node);
    }
}

void print_externals(FILE *dest,symbol_table to_print){
    node current_node;
    symbol current_symbol=NULL;
    current_node= get_head(to_print->table);
    while (current_node){
        current_symbol=get_node_data(current_node);
        if (is_extern_symbol(current_symbol)){
            char *name;
            unsigned long address,offset;
            name= get_symbol_name(current_symbol);
            address= get_symbol_base_address(current_symbol);
            offset= get_symbol_offset(current_symbol);
            fprintf(dest,"%s %04ld\n",name,address);
            fprintf(dest,"%s %04ld\n",name,offset);
        }
        current_node=get_next_node(current_node);
    }
}
//void add_symbol(symbol_table table,char *name,long value,long base_address,long offset,
//                                                    int is_entry,int is_extern,int is_data,int is_code,error *error1){
//    if (!is_legal_name(name)){
//        *error1=ILLEGAL_SYMBOL_NAME;
//    } else if(double_definition(table, name, is_extern, error1)){
//        symbol new_symbol;
//        new_symbol= init_symbol_with_values(name,value,base_address,offset,is_entry,is_extern,is_data,is_code);
//        push_symbol(table,new_symbol);
//    }
//}

int double_definition(symbol_table symbols, char *name, int is_extern, error *error1) {
    symbol old_symbol;
    old_symbol= get_symbol_by_name(symbols,name);
    if(old_symbol!=NULL){
        if (!(is_extern_symbol(old_symbol)&&is_extern)){
            *error1=DOUBLE_DEFINITION_OF_LABEL;
        }
        return 1;
    }
    return 0;
}

int is_legal_name(char *name) {
    boolean result=true;
    if(is_reserved_word(name)|| (strlen(name)>MAX_NAME_LENGTH)||!is_alpha_numeric_word(name)){
        result=false;
    }
    return result;
}

void update_addresses_of_data_symbols(symbol_table symbols,unsigned long final_ic){
    node current_node;
    symbol current_symbol=NULL;
    current_node= get_head(symbols->table);
    while (current_node){
        current_symbol=get_node_data(current_node);
        if (is_data_symbol(current_symbol)){
            unsigned long address;
            address= get_symbol_value(current_symbol);
            address+=final_ic;
            set_symbol_value(current_symbol,address);
        }
        current_node=get_next_node(current_node);
    }
}