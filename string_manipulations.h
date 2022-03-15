/*
* Created by Avishav & Sapir on March 2,2022
*/

#ifndef EX14_STRING_MANIPULATIONS_H
#define EX14_STRING_MANIPULATIONS_H

#include "boolean.h"

/**
 * this function trims whitespaces from the edges of the given string
 * @param str the wanted string
 * @return the string after trimming whitespaces from the edges
 */
char *trim_whitespace(char *str);

/**
 * split the given string to several strings
 * @param src string to split
 * @param dest 2D array to hold the output strings
 * @param delimiter delimiter
 * @return the number of separate strings
 */
int split(char *src, char **dest, const char *delimiter);

/**
 * check if given string represent the number zero.
 * @param str string to check
 * @return true if str is representation of 0, false otherwise
 */
boolean is_zero(char *str);

/**
 * convert string to a floating point number
 * @param str string to convert
 * @return 0 if the string contains non numeric chars
 */
int str_to_double(char *str, double *dest);

/**
 * convert string to int
 * @param str string to convert
 * @return 0 if the string contains non numeric chars
 */
int str_to_int(char *str,int *dest);

/**
* Return the first word in string with whitespaces
* @param str the complete string
* @return the first word in str with whitespaces
*/
char* get_first_word_in_line(char *str);

/**
 * Check if all the characters in word are alphanumerics
 * @param word work to check
 * @return true if all the characters are alphanumeric, false otherwise
 */
boolean is_alpha_numeric_word(char *word);

#endif /* EX14_STRING_MANIPULATIONS_H */