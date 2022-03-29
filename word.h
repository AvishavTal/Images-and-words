/*
* Created by avishav on 8.3.2022.
*/

#ifndef EX14_WORD_H
#define EX14_WORD_H
#include <stdio.h>
#include "ARE.h"
#include "addressing_mode.h"


/**
 * representation of machine word
 */
typedef struct word *word;
word init_word();
void print_word(FILE *dest, word to_print);
void set_address(word to_set,unsigned long new_address);
unsigned long get_address(word word1);
void delete_word(word to_delete);
void set_are(word to_set, are new_are);
void set_opcode(word to_set, unsigned int new_opcode);
void set_funct(word to_set, unsigned int new_funct);
void set_dest_register(word to_set, unsigned int reg_num);
void set_dest_addressing(word to_set, addressing_mode dest_addressing);
void set_src_register(word to_set, unsigned int reg_num);
void set_src_addressing(word to_set, addressing_mode src_addressing);
void set_immediate(word to_set, unsigned int immediate);
void set_data(word to_set, unsigned long new_data);
#endif
