//
// Created by avishav on 4.3.2022.
//
#include "file.h"
#include "macro_table.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include "data_image.h"
#define EXTENSION_LENGTH 5

struct file{
    char *name;

    /*the names of the output files with the proper extension*/
    char *name_as;
    char *name_am;
    char *name_ob;
    char *name_ent;
    char *name_ext;

    /*tables*/
    macro_table marcos;
    symbol_table symbols;
    data_image image;

    /*flags*/
    unsigned int has_passed_pre_assembler :1;
    unsigned int has_passed_first_scan :1;
    unsigned int has_passed_second_scan :1;
};

data_image get_data_image(file file1){
    return file1->image;
}



void set_name_am(file file);

void set_name_ob(file file);

void set_name_ext(file file);

void set_name_ent(file file);

void set_name_as(file file);

file init_file(char *name){
    file result;
    result=(file)malloc(sizeof(struct file));
    result->name=name;
    set_name_as(result);
    set_name_am(result);
    set_name_ob(result);
    set_name_ext(result);
    set_name_ent(result);
    result->marcos=init_macro_table();
    result->symbols=init_symbol_table();
    result->image=init_data_image();
    result->has_passed_first_scan=1;/*if first scan failed wil be changed to 0*/
    result->has_passed_pre_assembler=1;/*if pre-assembler failed wil be changed to 0*/
    result->has_passed_second_scan=1;
    return result;
}

void set_name_as(file file) {
    unsigned long len;
    len= strlen(file->name);
    len=len+EXTENSION_LENGTH;
    file->name_as=(char *) malloc(len);
    strcpy(file->name_as,file->name);
    strcat(file->name_as,".as");
}

void set_name_ent(file file) {
    unsigned long len;
    len= strlen(file->name);
    len=len+EXTENSION_LENGTH;
    file->name_ent=(char *) malloc(len);
    strcpy(file->name_ent,file->name);
    strcat(file->name_ent,".ent");
}

void set_name_ext(file file) {
    unsigned long len;
    len= strlen(file->name);
    len=len+EXTENSION_LENGTH;
    file->name_ext=(char *) malloc(len);
    strcpy(file->name_ext,file->name);
    strcat(file->name_ext,".ext");
}

void set_name_ob(file file) {
    unsigned long len;
    len= strlen(file->name);
    len=len+EXTENSION_LENGTH;
    file->name_ob=(char *) malloc(len);
    strcpy(file->name_ob,file->name);
    strcat(file->name_ob,".ob");
}

void set_name_am(file file) {
    unsigned long len;
    len= strlen(file->name);
    len=len+EXTENSION_LENGTH;
    file->name_am=(char *) malloc(len);
    strcpy(file->name_am,file->name);
    strcat(file->name_am,".am");
}

macro_table get_macro_table(file file){
    return file->marcos;
}

char *get_name_as(file file){
    return file->name_as;
}
char *get_name_am(file file){
    return file->name_am;
}
char *get_name_ob(file file){
    return file->name_ob;
}
char *get_name_ext(file file){
    return file->name_ext;
}
char *get_name_ent(file file){
    return file->name_ent;
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
symbol_table get_symbol_table(file file){
    return file->symbols;
}
