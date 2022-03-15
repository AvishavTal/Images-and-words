//
// Created by Sapir on 10.3.2022.
//

#ifndef EX14_FIRST_SCAN_H
#define EX14_FIRST_SCAN_H

#include <string.h>
#include "symbol_table.h"
#include "string_manipulations.h"
#include "file.h"
#include "instruction.h"
#include "parser.h"
#include "first_and_second_scan_constants.h"

char* pull_symbol_name(char *str);
void first_scan(file source);
#endif //EX14_FIRST_SCAN_H
