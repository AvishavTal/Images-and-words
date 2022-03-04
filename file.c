//
// Created by avishav on 4.3.2022.
//
#include "file.h"
#include <stdlib.h>
struct file{
    char *name;
    unsigned int has_passed_pre_assembler :1;
    unsigned int has_passed_first_scan :1;
};
file init_file(char *name){
    file result;
    result=(file)malloc(sizeof(struct file));
    result->name=name;
    result->has_passed_first_scan=1;/*if first scan failed wil be changed to 0*/
    result->has_passed_pre_assembler=1;/*if pre-assembler failed wil be changed to 0*/
    return result;
}
char *get_name(file file){
    return file->name;
}
int has_passed_pre_assembler(file file){
    return file->has_passed_pre_assembler;
}
int has_passed_first_scan(file file){
    return file->has_passed_first_scan;
}
void mark_pre_assembler_failed(file file){
    file->has_passed_pre_assembler=0;
}
void mark_first_scan_failed(file file){
    file->has_passed_first_scan=0;
}