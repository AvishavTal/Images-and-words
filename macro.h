//
// Created by Sapir on 28.2.2022.
//

#ifndef EX14_MACRO_H
#define EX14_MACRO_H

#include "linked_list.h"
#include "macro_body.h"
#include <stdio.h>

typedef struct macro *macro;
macro init_macro();
char *get_macro_name(macro macro);
void set_macro_name(macro macro, char *name);
macro_body get_macro_body(macro macro);
void macro_call(FILE *dest,macro to_print);
void set_macro_body(macro macro, macro_body body);
void append_line(macro macro, char *line);
char *next_line(macro macro);
void delete_macro(macro macro);

#endif //EX14_MACRO_H
