/*
* Created by Avishav & Sapir on March 1, 2022
*/

#ifndef EX14_SYMBOL_H
#define EX14_SYMBOL_H

#include <stdio.h>
#include "boolean.h"

typedef struct symbol *symbol;

/**
 * Returns new symbol with the wanted values
 * @param name the name of the symbol
 * @param address the address of the symbol
 * @param is_entry a flag that symbolizes whether the label is entry
 * @param is_extern a flag that symbolizes whether the label is extern
 * @param is_data a flag that symbolizes whether the label is data
 * @param is_code a flag that symbolizes whether the label is code
 * @return new symbol with the wanted values
 */
symbol init_symbol_with_values(char *name, unsigned long address, boolean is_entry, boolean is_extern, boolean is_data, boolean is_code);

/**
 * Returns the name of the symbol
 * @param curr_symbol the needed symbol
 * @return the name of the symbol
 */
char* get_symbol_name(symbol curr_symbol);

/**
 * Updates the name of the received symbol
 * @param curr_symbol the needed symbol
 * @param name the wanted name
 */
void set_symbol_name(symbol curr_symbol , char *name);

/**
 * Return the address of received symbol
 * @param curr_symbol the needed symbol
 * @return the address of the symbol
 */
unsigned long get_symbol_address(symbol curr_symbol);

/**
 * Receives new address and updates in the received symbol
 * @param curr_symbol the needed symbol
 * @param address the new address
 */
void set_symbol_address(symbol curr_symbol , unsigned long address);

/**
 * Return the base address of the symbol
 * @param curr_symbol the needed symbol
 * @return the base address of the symbol
 */
unsigned long get_symbol_base_address(symbol curr_symbol);

/**
 * Return the offset of the symbol
 * @param curr_symbol the needed symbol
 * @return  the offset of the symbol
 */
unsigned long get_symbol_offset(symbol curr_symbol);

/**
 * Set entry flag to true
 * @param to_mark the needed symbol
 */
void mark_entry(symbol to_mark);

/**
  * Returns if this symbol is an entry symbol
  * @param curr_symbol the needed symbol
  * @return true if this symbol is an entry symbol, false otherwise
  */
boolean get_is_entry_symbol(symbol curr_symbol);

/**
 * Returns if this symbol is an extern symbol
 * @param curr_symbol the needed symbol
 * @return true if this symbol is an extern symbol, false otherwise
 */
boolean get_is_extern_symbol(symbol curr_symbol);

/**
 * Returns if this symbol is an data symbol
 * @param curr_symbol the needed symbol
 * @return true if this symbol is an data symbol, false otherwise
 */
boolean get_is_data_symbol(symbol curr_symbol);

 /**
  * Delete the received symbol and free all its allocations
  * @param to_delete the needed symbol
  */
void delete_symbol(symbol to_delete);

void print_entry_symbol(FILE *dest,symbol to_print);
void print_extern_symbol(FILE *dest,symbol to_print);
void add_to_base_required(symbol to_update,unsigned long address);
void add_to_offset_required(symbol to_update,unsigned long address);

#endif