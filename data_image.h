/*
 Created by avishav on 10.3.2022.
*/

#ifndef EX14_DATA_IMAGE1_H
#define EX14_DATA_IMAGE1_H
#include <stdio.h>
#include "errors.h"

/**
 * representation of data image
 */
typedef struct image *data_image;
/**
 * @return new data image
 */
data_image init_data_image();
/**
 * print the given data image to the dest file
 * @param dest
 * @param image
 */
void print_data(FILE *dest,data_image image);
/**
 * delete the given data image
 * @param to_delete
 */
void delete_data(data_image to_delete);
/**
 * add the final ic to the address of all data words
 * @param image
 * @param final_ic
 */
void update_addresses(data_image image,long final_ic);
/**
 * get a string and add it to the data image
 * @param image
 * @param address address of the first char in the string
 * @param new_string the string to add
 * @param n_words wil hold the number of machine words this string takes
 * @param err hold the information of errors
 */
void add_string(data_image image, unsigned long address, char *new_string, int *n_words, error *err);
/**
 * get string represents a list of integers and add their values to the data image
 * @param image
 * @param address the address of the first int
 * @param line string representation of list of intetegers
 * @param n_words wil hold the number of machine words this list takes
 * @param err hold the information of errors
 */
void add_data_line(data_image image, unsigned long address, char *line, int *n_words, error *err);
#endif
