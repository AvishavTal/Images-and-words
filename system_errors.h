/*
* Created by Avishav & Sapir on March 15, 2022
*/

#ifndef EX14_SYSTEM_ERRORS_H
#define EX14_SYSTEM_ERRORS_H

#include <stdio.h>
#include "boolean.h"

/**
 * This function gets pointer and check if the allocation succeeded
 * @param pointer the allocated pointer
 * @return if the allocation succeeded return true, else exit with ALLOCATION_EXIT_CODE
 */
boolean is_allocation_succeeded(void* pointer);

/**
 * This function gets file and check if the file opened successfully
 * @param curr_file pointer to  a FILE
 * @param is_fatal true iff the program cant continue without openning this file
 * @return true if the file opened successfully
 */
boolean is_open_file_succeeded(FILE *curr_file, boolean is_fatal, const char *file_name);

#endif