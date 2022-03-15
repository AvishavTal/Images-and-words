/*
* Created by Avishav & Sapir on March 10,2022
*/

#ifndef EX14_PARSER_H
#define EX14_PARSER_H

#include "boolean.h"

int end_of_macro_definition(char *line);

int start_of_macro_definition(char *first_word);

/**
 * get word, trimming whitespaces and check if equal to .entry
 * @param word word to check
 * @return true if entry definition, false otherwise
 */
boolean is_entry_def(char *word);

/**
 * get word, trimming whitespaces and check if equal to .data
 * @param word word to check
 * @return true if data definition, false otherwise
 */
boolean is_data_def(char *word);

/**
 * get word, trimming whitespaces and check if equal to .string
 * @param word word to check
 * @return true if string definition, false otherwise
 */
boolean is_string_def(char *word);

/**
 * get word, trimming whitespaces and check if equal to .extern
 * @param word word to check
 * @return true if extern definition, false otherwise
 */
boolean is_extern_def(char *word);

/**
 * get line, trimming whitespaces and check if ends with a symbol definition - not check errors here
 * @param word line to check
 * @return true if symbol, false otherwise
 */
boolean is_symbol_def(char *word);

/**
 * get line, trimming whitespaces and check if starts with ; (ignore whitespaces)
 * @param line line to check
 * @return true if comment, false otherwise
 */
boolean is_comment(char *line);

/**
 * get line and check if the line includes whitespaces only
 * @param line line to check
 * @return true if empty, false otherwise
 */
boolean is_empty(char *line);

/**
 * gets line, trimming whitespaces and check if its starts and ends with string boundary
 * @param line line to check
 * @return true if string, false otherwise
 */
boolean is_string(char *line);

/**
 * gets word, trimming whitespaces and check if equal to reserved word (as macro, endm, register name, operator name etc.)
 * @param word word to check
 * @return true if reserved word, false otherwise
 */
boolean is_reserved_word(char *word);

#endif /* EX14_PARSER_H */