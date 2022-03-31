/*
* Created by Avishav & Sapir on March 9, 2022
*/

#ifndef EX14_MACRO_H
#define EX14_MACRO_H

#include <stdio.h>
#include "linked_list.h"
#include "macro_body.h"

/**
 * Representation of macro
 */
typedef struct macro *macro;

/**
 * Create new macro and reset all variables
 * @return
 */
macro init_macro();

/**
 * Gets a macro and returns its name
 * @param macro the needed macro
 * @return macro name
 */
char *get_macro_name(macro macro);

/**
 * Gets a macro and requested name and update its name
 * @param macro the needed macro
 * @param name requested name
 */
void set_macro_name(macro macro, char *name);

/**
 * Append line to the body of the macro
 * @param macro the needed macro
 * @param line new line
 */
void append_line(macro macro, char *line);

/**
 * free the memory of the macro
 * @param to_delete the wanted macro to delete
 */
void delete_macro(macro to_delete);

/**
 * print macro for dest file
 * @param dest destination file to write into
 * @param to_print required macro to print
 */
void macro_call(FILE *dest,macro to_print);

#endif