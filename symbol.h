//
// Created by Sapir on 28.2.2022.
//

#ifndef EX14_SYMBOL_H
#define EX14_SYMBOL_H


typedef struct symbol *symbol;
symbol init_symbol();
symbol init_symbol_with_values(char *name, unsigned long value, unsigned long base_address, unsigned long offset, int is_entry, int is_extern, int is_data, int is_code);
void update_symbol(symbol symbol, char* name, unsigned long value, unsigned long base_address, unsigned long offset);
char* get_symbol_name(symbol symbol);
void set_symbol_name(symbol symbol , char *name);
void delete_symbol(symbol to_delete);
unsigned long get_symbol_value(symbol symbol);
void set_symbol_value(symbol symbol , unsigned long value);
unsigned long get_symbol_base_address(symbol symbol);
void set_symbol_base_address(symbol symbol , unsigned long base_address);
unsigned long get_symbol_offset(symbol symbol);
void set_symbol_offset(symbol symbol , unsigned long offset);
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


