//
// Created by avishav on 7.3.2022.
//

#ifndef EX14_SYMBOL_TABLE_H
#define EX14_SYMBOL_TABLE_H
#include "symbol.h"
#include "errors.h"
#include <stdio.h>
typedef struct symbol_table *symbol_table;
symbol_table init_symbol_table();
symbol get_symbol_by_name(symbol_table symbols, char *symbol_name);
//todo check if address and offset in range
void add_symbol(symbol_table table,char *name,long value,long base_address,long offset,int is_entry,int is_extern,int is_data,int is_code,error *error1);
void add_symbol_seggestion(symbol_table table, char *name,long value, int is_entry, int is_extern, int is_data, int is_code, error *error1);//todo
void delete_symbol_table(symbol_table to_delete);
void push_symbol(symbol_table to_update,symbol to_push);
void print_entries(FILE *dest,symbol_table to_print);
void print_externals(FILE *dest,symbol_table to_print);
void update_symbol_table(symbol_table symbols, long final_ic, long final_dc);//todo - im not sure what else is needed
#endif //EX14_SYMBOL_TABLE_H
