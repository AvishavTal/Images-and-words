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
//void add_symbol(symbol_table symbols,char *symbol_name,long address,long base_address,long offset,int is_entry,int is_extern,int is_data,int is_code,error *error1);
void add_symbol(symbol_table symbols, char *symbol_name, unsigned long address, int is_entry, int is_extern, int is_data, int is_code, error *error1);
void delete_symbol_table(symbol_table to_delete);
void push_symbol(symbol_table to_update,symbol to_push);
void print_entries(FILE *dest,symbol_table to_print);
void print_externals(FILE *dest,symbol_table to_print);
void update_addresses_of_data_symbols(symbol_table symbols,unsigned long final_ic);
#endif //EX14_SYMBOL_TABLE_H
