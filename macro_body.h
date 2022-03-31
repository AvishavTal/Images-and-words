/*
* Created by Avishav & Sapir on March 10, 2022
*/

#ifndef EX14_MACRO_BODY_H
#define EX14_MACRO_BODY_H

#include <stdio.h>

/**
 * Representation of macro body
 */
typedef struct body *macro_body;

/**
 * Creates new macro body  and reset all variables
 * @return new macro body
 */
macro_body init_body();

/**
 * free the memory of all the lines in macro body
 * @param to_delete macro body to delete
 */
void delete_body(macro_body to_delete);

/**
 * Gets line and add this line to macro body
 * @param to_update macro body to update
 * @param line wanted line
 */
void append_line_to_body(macro_body to_update,char *line);

/**
 * Gets macro body and print all lines to file
 * @param dest wanted file to print into
 * @param to_print macro body to print
 */
void print_body(FILE *dest, macro_body to_print);

#endif