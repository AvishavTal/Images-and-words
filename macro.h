//
// Created by avishav on 28.2.2022.
//

#ifndef EX14_MACRO_H
#define EX14_MACRO_H
typedef struct macro *macro;
macro init_macro();
char **get_macro_body(macro macro);
char *get_macro_name(macro macro);
void set_macro_name(macro macro, char *name);
void set_macro_body(macro macro, char **body);
void append_line(macro macro, char *line);
#endif //EX14_MACRO_H
