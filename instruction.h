/*
* Created by Avishav & Sapir on March 1, 2022
*/

#ifndef EX14_INSTRUCTION_H
#define EX14_INSTRUCTION_H

#include <stdio.h>
#include "symbol_table.h"
#include "errors.h"

/**
 * representation of an instruction in our assembly
 */
typedef struct instruction *instruction;

/**
 * figure out which instruction written in the line and return representation of this instruction
 * @param line string representation of instruction
 * @param symbols symbol table of the program input
 * @param ic number of machine words instruction takes until this instruction
 * @param err hold the information of error if detected
 * @return
 */
instruction init_instruction(char *line, symbol_table symbols, unsigned long ic, error *err);

/**
 * @param instruction1
 * @return the number of machine words the instruction takes
 */
int get_n_words(instruction instruction1);

/**
 * print the given instruction
 * @param dest
 * @param to_print
 */
void print_instruction(FILE *dest,instruction to_print);

/**
 * delete the given instruction
 * @param to_delete
 */
void delete_instruction(instruction to_delete);

#endif