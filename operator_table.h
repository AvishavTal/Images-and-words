/*
* Created by Avishav & Sapir on March 2, 2022
*/

#ifndef EX14_OPERATOR_TABLE_H
#define EX14_OPERATOR_TABLE_H

#include "addressing_mode.h"

typedef struct operator *operator;

/**
 * Gets operator name and return the wanted register if exist
 * @param name the wanted operator name
 * @return the wanted operator if exist, NULL otherwise
 */
operator get_operator_by_name(char *name);


/**
 * Returns the operator code
 * @param op wanted operator
 * @return the operator code
 */
int get_opcode(operator op);

/**
 * Returns the operator funct
 * @param op wanted operator
 * @return the operator funct
 */
int get_funct(operator op);

/**
 * Returns the number of operands of this operator
 * @param op wanted operator
 * @return the number of operands of this operator
 */
int get_n_operands(operator op);

/**
 * Check if the source operand is legal addressing mode
 * @param op wanted operator
 * @param mode addressing mode
 * @return 0 if legal source addressing mode, 1 otherwise
 */
unsigned int is_legal_source_addressing_mode(operator op,addressing_mode mode);

/**
 * Check if the dest operand is legal addressing mode
 * @param op wanted operator
 * @param mode addressing mode
 * @return 0 if legal dest addressing mode, 1 otherwise
 */
unsigned int is_legal_dest_addressing_mode(operator op,addressing_mode mode);

#endif