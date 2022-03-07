//
// Created by Sapir on 28.2.2022.
//

#ifndef EX14_MACRO_H
#define EX14_MACRO_H

#include "linked_list.h"

typedef struct macro *macro;
macro init_macro();
char *get_macro_name(macro macro);
void set_macro_name(macro macro, char *name);
list get_macro_body(macro macro);
void set_macro_body(macro macro, list body);
void append_line(macro macro, char *line);
char *next_line(macro macro);

#endif //EX14_MACRO_H
