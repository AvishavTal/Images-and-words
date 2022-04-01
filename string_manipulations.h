/*
* Created by Avishav & Sapir on March 2, 2022
*/

#ifndef EX14_STRING_MANIPULATIONS_H
#define EX14_STRING_MANIPULATIONS_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "boolean.h"

/**
 * trim the whitespaces from the edges of the given string
 * @param str
 * @return
 */
char* trim_whitespace(char *str);

/**
 * split the given string to several strings
 * @param src the string to split
 * @param dest 2D array to hold the otput strings
 * @param delimiter
 * @return the number of strings
 */
int split(char *src, char ***dest, const char *delimiter);

/**
 * check if given string represent the number zero.
 * @param str
 * @return 0 iff str is not representation of 0.
 */
char is_zero(char *str);

/**
 * convert string to int
 * @param str string to convert
 * @return 0 iff the string contains non numeric chars
 */
int str_to_int(char *str,int *dest);

/**
 * gets word and check if all the characters is alphanumeric
 * @param word word to check
 * @return true if all the characters is alphanumeric, false otherwise
 */
boolean is_alpha_numeric_word(char *word);

/**
 * count the non spaces chars
 * @param string
 * @return the number of non spaces chars in string
 */
char* str_tok(char *src,const char *delim);

/**
 * count the non spaces chars
 * @param string
 * @return the number of non spaces chars in string
 */
unsigned long number_of_not_spaces_chars(char *string);

#endif