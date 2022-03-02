//
// Created by avishav on 1.3.2022.
//

#ifndef EX14_OBJ_LINE_H
#define EX14_OBJ_LINE_H
typedef struct obj_line *ob_line;
unsigned int get_a(ob_line line);
unsigned int get_b(ob_line line);
unsigned int get_c(ob_line line);
unsigned int get_d(ob_line line);
unsigned int get_e(ob_line line);
long get_address(ob_line line);
void set_address(ob_line line, long new_address);
void set_a(ob_line line, unsigned int new_a);
void set_b(ob_line line, unsigned int new_b);
void set_c(ob_line line, unsigned int new_c);
void set_d(ob_line line, unsigned int new_d);
void set_e(ob_line line, unsigned int new_e);
#endif //EX14_OBJ_LINE_H
