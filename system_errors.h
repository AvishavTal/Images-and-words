/*
* Created by Avishav & Sapir on March 15,2022
*/

#ifndef EX14_SYSTEM_ERRORS_H
#define EX14_SYSTEM_ERRORS_H

#include "boolean.h"
#include "file.h"

/**
 * This function gets pointer and check if the allocation succeeded
 * @param pointer the allocated pointer
 * @return if the allocation succeeded return true, else exit with ALLOCATION_EXIT_CODE
 */
boolean is_allocation_succeeded(void* pointer);

/**
 * This function gets file and check if the file opens successfully
 * @param curr_file the needed file
 * @return true if the file opens successfully, else exit with OPEN_FILE_EXIT_CODE
 */
boolean is_open_file_succeeded(file* curr_file);

#endif /* EX14_SYSTEM_ERRORS_H */