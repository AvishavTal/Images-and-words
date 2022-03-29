/*
* Created by avishav on 10.3.2022.
*/

#ifndef EX14_MACRO_BODY_H
#define EX14_MACRO_BODY_H
#include <stdio.h>
typedef struct body *macro_body;
macro_body init_body();
void delete_body(macro_body to_delete);
void append_line_to_body(macro_body to_update,char *line);
void print_body(FILE *dest, macro_body to_print);
#endif
