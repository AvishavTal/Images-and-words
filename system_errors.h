/*
* Created by Avishav & Sapir on March 15,2022
*/

#ifndef EX14_SYSTEM_ERRORS_H
#define EX14_SYSTEM_ERRORS_H

#include "boolean.h"

/**
 * This function gets pointer and check if the allocation succeeded
 * @param pointer the allocated pointer
 * @return if the allocation succeeded return true, else exit with exit_code
 */
boolean is_allocation_succeeded(void* pointer);

#endif //EX14_SYSTEM_ERRORS_H
