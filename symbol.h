//
// Created by Sapir on 28.2.2022.
//

#ifndef EX14_SYMBOL_H
#define EX14_SYMBOL_H


typedef struct symbol *symbol;
symbol init_symbol();
void update_symbol(symbol symbol, char* name, long value, long base_address, long offset);
char* get_symbol_name(symbol symbol);
void set_symbol_name(symbol symbol , char *name);
long get_symbol_value(symbol symbol);
void set_symbol_value(symbol symbol , long value);
long get_symbol_base_address(symbol symbol);
void set_symbol_base_address(symbol symbol , long base_address);
long get_symbol_offset(symbol symbol);
void set_symbol_offset(symbol symbol , long offset);
//void set_symbol_attribute(symbol symbol , attribute attribute);
void mark_entry(symbol to_mark);
void mark_extern(symbol to_mark);
void mark_code(symbol to_mark);
void mark_data(symbol to_mark);
int is_entry_symbol(symbol symba);
int is_extern_symbol(symbol symba);
int is_code_symbol(symbol symba);
int is_data_symbol(symbol symba);
#endif //EX14_SYMBOL_H


