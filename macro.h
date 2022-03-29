

#ifndef EX14_MACRO_H
#define EX14_MACRO_H

#include "linked_list.h"
#include "macro_body.h"
#include <stdio.h>

typedef struct macro *macro;
macro init_macro();
char *get_macro_name(macro macro);
void set_macro_name(macro macro, char *name);
void macro_call(FILE *dest,macro to_print);
void append_line(macro macro, char *line);
void delete_macro(macro to_delete);
#endif
