/**
 * hold the information of a file
 */

#ifndef EX14_FILE_H
#define EX14_FILE_H
#include "macro_table.h"
#include "symbol_table.h"
#include "data_image.h"

typedef struct file *file;
file init_file(char *name);
char *get_name(file file);
char *get_name_as(file file);
void set_name_as(file file);
char *get_name_am(file file);
void set_name_am(file file);
char *get_name_ob(file file);
void set_name_ob(file file);
char *get_name_ent(file file);
void set_name_ent(file file);
char *get_name_ext(file file);
void set_name_ext(file file);
macro_table get_macro_table(file file);
symbol_table get_symbol_table(file file);
data_image get_data_image(file file1);
int has_passed_pre_assembler(file file);
void mark_pre_assembler_failed(file file);
int has_passed_first_scan(file file);
void mark_first_scan_failed(file file);
long get_final_ic(file file);
void set_final_ic(file file, long final_ic);
long get_final_dc(file file);
void set_final_dc(file file, long final_dc);
#endif //EX14_FILE_H
