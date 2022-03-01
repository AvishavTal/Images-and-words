//
// Created by avishav on 28.2.2022.
//

#ifndef EX14_SYMBOL_H
#define EX14_SYMBOL_H

#include "attribute.h"

typedef struct symbol *symbol;
symbol init_symbol();
void update_symbol(symbol symbol, char* name, long value, long base_address, long offset, attribute attribute);
char* get_name(symbol symbol);
void set_name(symbol symbol , char *name);
long get_value(symbol symbol);
void set_value(symbol symbol , long value);
long get_base_address(symbol symbol);
void set_base_address(symbol symbol , long base_address);
long get_offset(symbol symbol);
void set_offset(symbol symbol , long offset);
attribute get_attribute(symbol symbol);
void set_attribute(symbol symbol , attribute attribute);


#endif //EX14_SYMBOL_H


