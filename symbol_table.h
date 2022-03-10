//
// Created by avishav on 7.3.2022.
//

#ifndef EX14_SYMBOL_TABLE_H
#define EX14_SYMBOL_TABLE_H
#include "symbol.h"
#include <stdio.h>
typedef struct symbol_table *symbol_table;
symbol_table init_symbol_table();
symbol get_symbol_by_name(symbol_table symbols, char *symbol_name);
void delete_symbol_table(symbol_table to_delete);
void push_symbol(symbol_table to_update,symbol to_push);
void print_entries(FILE *dest,symbol_table to_print);
void print_externals(FILE *dest,symbol_table to_print);
#endif //EX14_SYMBOL_TABLE_H
