//
// Created by avishav on 28.2.2022.
//

#ifndef EX14_INSTRUCTION_H
#define EX14_INSTRUCTION_H

#include <stdio.h>
#include "symbol_table.h"

typedef struct instruction *instruction;
instruction init_instruction(char *line, symbol_table symbols, unsigned long *ic);
void print_instruction(FILE *dest,instruction to_print);
void delete_instruction(instruction to_delete);
#endif //EX14_INSTRUCTION_H
