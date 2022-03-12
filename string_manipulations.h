//
// Created by avishav on 2.3.2022.
//

#ifndef EX14_STRING_MANIPULATIONS_H
#define EX14_STRING_MANIPULATIONS_H
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
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
int split(char *src, char **dest, const char *delimiter);

/**
 * convert string to a floating point number
 * @param str string to convert
 * @return 0 iff the string contains non numeric chars
 */
int str_to_double(char *str, double *dest);

/**
 * check if given string represent the number zero.
 * @param str
 * @return 0 iff str is not representation of 0.
 */
char is_zero(char *str);

/**
* return the first word in string without whitespaces
* @param str
* @return the first word in str without whitespaces
*/
char* get_first_word_in_line(char *str);
#endif //EX14_STRING_MANIPULATIONS_H
