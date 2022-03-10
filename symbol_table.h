//
// Created by avishav on 7.3.2022.
//

#ifndef EX14_SYMBOL_TABLE_H
#define EX14_SYMBOL_TABLE_H
#include "symbol.h"
typedef struct symbol_table *symbol_table;
symbol_table init_symbol_table();
symbol get_symbol_by_name(char *symbol_name);
#endif //EX14_SYMBOL_TABLE_H
