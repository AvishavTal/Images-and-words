/**
 * hold the information of a file
 */

#ifndef EX14_FILE_H
#define EX14_FILE_H
typedef struct file *file;
file init_file(char *name);
char *get_name(file file);
int has_passed_pre_assembler(file file);
int has_passed_first_scan(file file);
void mark_pre_assembler_failed(file file);
void mark_first_scan_failed(file file);
#endif //EX14_FILE_H
