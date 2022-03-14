//
// Created by avishav on 10.3.2022.
//

#ifndef EX14_PARSER_H
#define EX14_PARSER_H
#include "boolean.h"

/**
 * get word and check if equal to .entry
 * @param str word to check
 * @return true if entry definition, -1 otherwise
 */
boolean is_entry_def(char *str);
/**
 * get word and check if equal to .data
 * @param str word to check
 * @return true if data definition, -1 otherwise
 */
boolean is_data_def(char *str);
/**
 * get word and check if equal to .string
 * @param str word to check
 * @return true if string definition, -1 otherwise
 */
boolean is_string_def(char *str);
/**
 * get word and check if equal to .extern
 * @param str word to check
 * @return true if extern definition, -1 otherwise
 */
boolean is_extern_def(char *str);
/**
 * get line and check if start with a label definition - not check errors here
 * @param str line to check
 * @param chars_num number to update - How many characters are there from the beginning of the line to the colon(:) including
 * @return true if symbol, -1 otherwise
 */
boolean is_symbol_def(char *str);
/**
 * get line and check if starts with : (ignore whitespaces)
 * @param str word to check
 * @return true if comment, -1 otherwise
 */
boolean is_comment(char *line);
/**
 * get line and check if the line includes whitespaces only
 * @param str line to check
 * @return true if empty, -1 otherwise
 */
boolean is_empty(char *line);
/**
 * gets line and check if after trimming whitespaces its start and end with "
 * @param line line to check
 * @return true if string, -1 otherwise
 */
boolean is_string(char *line);
/**
 * gets word and check if equal to reserved word (as macro, endm, register name, operator name etc.)
 * @param word word to check
 * @return true if reserved word, false otherwise
 */
boolean is_reserved_word(char *word);//todo

#endif //EX14_PARSER_H
