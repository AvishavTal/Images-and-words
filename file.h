/**
 * hold the information of a file
 */

#ifndef EX14_FILE_H
#define EX14_FILE_H
#include "macro_table.h"
typedef struct file *file;
file init_file(char *name);
char *get_name_as(file file);
char *get_name_am(file file);
char *get_name_ob(file file);
char *get_name_ext(file file);
char *get_name_ent(file file);
char *get_name(file file);
int has_passed_pre_assembler(file file);
int has_passed_first_scan(file file);
void mark_pre_assembler_failed(file file);
void mark_first_scan_failed(file file);
macro_table get_macro_table(file file);
#endif //EX14_FILE_H
