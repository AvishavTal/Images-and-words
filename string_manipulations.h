

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
char *trim_whitespace(char *str);
/**
 * split the given string to several strings
 * @param src the string to split
 * @param dest 2D array to hold the otput strings
 * @param delimiter
 * @return the number of strings
 */
int split(char *src, char ***dest, const char *delimiter);


/**
 * convert string to int
 * @param str string to convert
 * @return 0 iff the string contains non numeric chars
 */
int str_to_int(char *str,int *dest);

/**
 * check if given string represent the number zero.
 * @param str
 * @return 0 iff str is not representation of 0.
 */
char is_zero(char *str);

boolean is_alpha_numeric_word(char *word);
char *str_tok(char *src,const char *delim);
unsigned long number_of_not_spaces_chars(char *string);
#endif
