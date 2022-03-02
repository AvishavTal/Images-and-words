//
// Created by avishav on 28.2.2022.
//

#ifndef EX14_SYMBOL_H
#define EX14_SYMBOL_H

#include "attribute.h"

typedef struct symbol *symbol;
symbol init_symbol();
void update_symbol(symbol symbol, char* name, long value, long base_address, long offset, attribute attribute);
char* get_symbol_name(symbol symbol);
void set_symbol_name(symbol symbol , char *name);
long get_symbol_value(symbol symbol);
void set_symbol_value(symbol symbol , long value);
long get_symbol_base_address(symbol symbol);
void set_symbol_base_address(symbol symbol , long base_address);
long get_symbol_offset(symbol symbol);
void set_symbol_offset(symbol symbol , long offset);
attribute get_symbol_attribute(symbol symbol);
void set_symbol_attribute(symbol symbol , attribute attribute);


#endif //EX14_SYMBOL_H


