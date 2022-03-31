/*
* Created by Avishav & Sapir on March 8, 2022
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
/**
 * print word to file
 * @param dest
 * @param to_print
 */
void print_word(FILE *dest, word to_print);
/**
 * set the address of the word in the memory
 * @param to_set
 * @param new_address
 */
void set_address(word to_set,unsigned long new_address);
/**
 * @param word1
 * @return the address of the given word
 */
unsigned long get_address(word word1);
/**
 * delete the given word
 * @param to_delete
 */
void delete_word(word to_delete);
/**
 * set the are filed of the given word
 * @param to_set
 * @param new_are
 */
void set_are(word to_set, are new_are);
/**
 * set the opcode filed of the given word
 * @param to_set
 * @param new_opcode
 */
void set_opcode(word to_set, unsigned int new_opcode);
/**
 * set the funct filed of the given word
 * @param to_set
 * @param new_funct
 */
void set_funct(word to_set, unsigned int new_funct);
/**
 * set the dest register filed of the given word
 * @param to_set
 * @param reg_num
 */
void set_dest_register(word to_set, unsigned int reg_num);
/**
 * set the dest addressing method of the given word
 * @param to_set
 * @param dest_addressing
 */
void set_dest_addressing(word to_set, addressing_mode dest_addressing);
/**
 * set the source register filed of the given word
 * @param to_set
 * @param reg_num
 */
void set_src_register(word to_set, unsigned int reg_num);
/**
 * set the source addressing method of the given word
 * @param to_set
 * @param src_addressing
 */
void set_src_addressing(word to_set, addressing_mode src_addressing);
/**
 * set the value of the given word to be the given immediate int
 * @param to_set
 * @param immediate
 */
void set_immediate(word to_set, unsigned int immediate);

#endif