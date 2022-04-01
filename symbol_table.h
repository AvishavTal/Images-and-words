/*
* Created by Avishav & Sapir on March 7, 2022
*/

#ifndef EX14_SYMBOL_TABLE_H
#define EX14_SYMBOL_TABLE_H

#include <string.h>
#include "symbol.h"
#include "boolean.h"
#include "errors.h"


typedef struct symbol_table *symbol_table;

/**
 * Returns new symbol_table with default values
 * @return new symbol_table with default values
 */
symbol_table init_symbol_table();

/**
 * Add to the table new symbol if the received name is legal name and not exist in the table already
 * @param symbols table of symbols to which we want to add a symbol
 * @param symbol_name wanted name for the new symbol
 * @param address new symbol address
 * @param is_entry a flag that symbolizes whether the symbol is entry
 * @param is_extern a flag that symbolizes whether the symbol is extern
 * @param is_data a flag that symbolizes whether the symbol is data
 * @param is_code a flag that symbolizes whether the symbol is code
 * @param err error code is saved here if an error occurred
 */
void add_symbol(symbol_table symbols, char *symbol_name, unsigned long address, boolean is_entry, boolean is_extern,
                boolean is_data, boolean is_code, error *err);

/**
 * Returns the symbol by name
 * @param symbols table of symbols in which to search for the name
 * @param symbol_name wanted symbol's name
 * @return the symbol by name
 */
symbol get_symbol_by_name(symbol_table symbols, char *symbol_name);

/**
 * Delete all the symbols in the table and the table itself
 * @param to_delete wanted table to delete
 */
void delete_symbol_table(symbol_table to_delete);

/**
 * Print to file all the symbols defined as entry in the table
 * @param dest file to print to
 * @param to_print table of symbols
 */
void print_entries(FILE *dest,symbol_table to_print);

/**
 * Print to file all the symbols defined as extern in the table
 * @param dest file to print to
 * @param to_print table of symbols
 */
void print_externals(FILE *dest,symbol_table to_print);

/**
 * Push all data symbols to the end of the table
 * @param symbols table of symbols
 * @param final_ic number of instruction counter after first scan
 */
void update_addresses_of_data_symbols(symbol_table symbols,unsigned long final_ic);

#endif