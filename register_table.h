//
// Created by avishav on 10.3.2022.
//

#ifndef EX14_REGISTER_TABLE_H
#define EX14_REGISTER_TABLE_H

#include "boolean.h"

typedef struct reg *regyster;

/**
 * Gets register name and return the wanted register if exist
 * @param name the wanted register name
 * @return 
 */
regyster get_register_by_name(char *name);


int get_reg_code(regyster register1);
boolean get_is_valid_index(regyster reg);

#endif //EX14_REGISTER_TABLE_H
