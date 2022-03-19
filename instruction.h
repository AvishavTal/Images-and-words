//
// Created by avishav on 28.2.2022.
//

#ifndef EX14_INSTRUCTION_H
#define EX14_INSTRUCTION_H

#include <stdio.h>
#include "symbol_table.h"
#include "errors.h"

typedef struct instruction *instruction;
instruction init_instruction(char *line, symbol_table symbols, unsigned long ic, error *err);
int get_n_words(instruction instruction1);
void print_instruction(FILE *dest,instruction to_print);
void delete_instruction(instruction to_delete);
#endif //EX14_INSTRUCTION_H
