//
// Created by avishav on 2.3.2022.
//

#ifndef EX14_MACRO_TABLE_H
#define EX14_MACRO_TABLE_H
#include "macro.h"
typedef struct macro_table *macro_table;
macro_table init_macro_table();
void delete_table();
macro get_macro_by_name(macro_table table, char *name);
void push_macro(macro_table table, macro new_macro);

#endif //EX14_MACRO_TABLE_H
