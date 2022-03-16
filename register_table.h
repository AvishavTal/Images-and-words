/*
** Created by Avishav & Sapir on March 10,2022
*/

#ifndef EX14_REGISTER_TABLE_H
#define EX14_REGISTER_TABLE_H

#include "boolean.h"

typedef struct reg *regyster;

/**
 * Gets register name and return the wanted register if exist
 * @param name the wanted register name
 * @return the wanted register if exist, NULL otherwise
 */
regyster get_register_by_name(char *name);

/**
 * Returns the register code
 * @param reg wanted register
 * @return the register code
 */
int get_reg_code(regyster reg);

/**
 * Returns the register index
 * @param reg
 * @return
 */
boolean get_is_valid_index(regyster reg);

#endif /* EX14_REGISTER_TABLE_H */