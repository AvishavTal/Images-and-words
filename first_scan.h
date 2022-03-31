/*
* Created by Avishav & Sapir on March 10, 2022
*/

#ifndef EX14_FIRST_SCAN_H
#define EX14_FIRST_SCAN_H

#include "file.h"

/**
 * In the first scan we find
 * The first scan run only if the pre assembled ends successfully
 * In the first scan we perform the following:
 * 1. Find the errors if exist and print them
 * 2. Calculate the ic and the dc
 * 3. Enter symbols to symbols table
 * 4. Enter data to data table
 * @param source information about file in the program
 */
void first_scan(file source);

#endif