/*
* Created by Avishav & Sapir on March 2, 2022
*/

#ifndef EX14_MACRO_TABLE_H
#define EX14_MACRO_TABLE_H

#include "macro.h"

/**
 * Representation of macro table
 */
typedef struct macro_table *macro_table;

/**
 * Creates new macro table and reset all variables
 * @return new macro body
 */
macro_table init_macro_table();

/**
 * This function gets macro name and return the macro object
 * * @param macros macro table to search in
 * @param name macro required name
 * @return macro object
 */
macro get_macro_by_name(macro_table macros, char *name);

/**
 * Gets macro and insert to macro table
 * @param table macro table to update
 * @param new_macro macro to insert
 */
void push_macro(macro_table table, macro new_macro);

/**
 * free the memory of all macros in macro table
 * @param to_delete macro table to delete
 */
void delete_macro_table(macro_table to_delete);

#endif