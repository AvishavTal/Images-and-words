/*
* Created by Avishav & Sapir on March 4, 2022
*/

#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "macro_table.h"
#include "symbol_table.h"
#include "data_image.h"
#include "boolean.h"
#include "system_errors.h"

#define EXTENSION_LENGTH 5

struct file {
    char *name;

    /* the names of the output files with the proper extension */
    char *name_as;
    char *name_am;
    char *name_ob;
    char *name_ent;
    char *name_ext;

    /* tables */
    macro_table marcos;
    symbol_table symbols;
    data_image image;

    /* flags */
    boolean is_ob_file_exist;
    boolean has_passed_pre_assembler;
    boolean has_passed_first_scan;
    boolean has_passed_second_scan;

    long ic_final;
    long dc_final;
};

/* private function declaration */
void set_name_as(file file);
void set_name_am(file file);
void set_name_ob(file file);
void set_name_ent(file file);
void set_name_ext(file file);
/* end of private function declaration */



/* public functions implementation */
file init_file(char *name) {
    file result;
    result = (file)malloc(sizeof(struct file));
    if (is_allocation_succeeded(result)) {
        result->name = name;
        set_name_as(result);
        set_name_am(result);
        set_name_ob(result);
        set_name_ext(result);
        set_name_ent(result);
        result->marcos = init_macro_table();
        result->symbols = init_symbol_table();
        result->image = init_data_image();
        result->has_passed_first_scan = true; /* if first scan failed will be changed to false */
        result->has_passed_pre_assembler = true; /* if pre-assembler failed wil be changed to false */
        result->has_passed_second_scan = true;
        result->ic_final = 0;
        result->dc_final = 0;
    }
    return result;
}

char* get_name_as(file file) {
    return file->name_as;
}

char* get_name_am(file file) {
    return file->name_am;
}

char* get_name_ob(file file) {
    return file->name_ob;
}

macro_table get_macro_table(file file) {
    return file->marcos;
}

symbol_table get_symbol_table(file file) {
    return file->symbols;
}

data_image get_data_image(file file1) {
    return file1->image;
}

boolean is_ob_file_exist(file file) {
    return file->is_ob_file_exist;
}

void mark_ob_file_exist(file file) {
    file->is_ob_file_exist = true;
}

void mark_ob_file_not_exist(file file) {
    file->is_ob_file_exist = false;
}

boolean has_passed_pre_assembler(file file) {
    return file->has_passed_pre_assembler;
}

void mark_pre_assembler_failed(file file) {
    file->has_passed_pre_assembler = false;
}

boolean has_passed_first_scan(file file) {
    return file->has_passed_first_scan;
}

void mark_first_scan_failed(file file) {
    file->has_passed_first_scan = false;
}

boolean has_passed_second_scan(file file) {
    return file->has_passed_second_scan;
}

void mark_second_scan_failed(file file) {
    file->has_passed_second_scan = false;
}

long get_final_ic(file file) {
    return file->ic_final;
}

void set_final_ic(file file, long final_ic) {
    file->ic_final = final_ic;
}

long get_final_dc(file file) {
    return file->dc_final;
}

void set_final_dc(file file, long final_dc) {
    file->dc_final = final_dc;
}

void tear_down(file to_delete) {
    free(to_delete->name_as);
    free(to_delete->name_am);
    free(to_delete->name_ob);
    free(to_delete->name_ext);
    free(to_delete->name_ent);
    delete_symbol_table(to_delete->symbols);
    delete_macro_table(to_delete->marcos);
    delete_data(to_delete->image);
    free(to_delete);
}

void make_ent_file(file source) {
    FILE *dest;
    dest = fopen(source->name_ent,"w");
    if (is_open_file_succeeded(dest,true, source->name_ent)) {
        print_entries(dest,source->symbols);
        fclose(dest);
    }
}

void make_ext_file(file source) {
    FILE *dest;
    dest = fopen(source->name_ext,"w");
    if (is_open_file_succeeded(dest,true, source->name_ext)) {
        print_externals(dest, source->symbols);
        fclose(dest);
    }
}
/* end of public functions implementation */




/* private functions implementation */
/*
 * Set the name of the file to be the accepted name with the .as extension
 */
void set_name_as(file file) {
    unsigned long len;
    len = strlen(file->name);
    len = len+EXTENSION_LENGTH;
    file->name_as = (char*)calloc(1,len);
    if (is_allocation_succeeded(file->name_as)) {
        strcpy(file->name_as, file->name);
        strcat(file->name_as, ".as");
    }
}

/*
 * Set the name of the file to be the accepted name with the .am extension
 */
void set_name_am(file file) {
    unsigned long len;
    len = strlen(file->name);
    len = len+EXTENSION_LENGTH;
    file->name_am = (char*)calloc(1,len);
    if (is_allocation_succeeded(file->name_am)) {
        strcpy(file->name_am, file->name);
        strcat(file->name_am, ".am");
    }
}

/*
 * Set the name of the file to be the accepted name with the .ob extension
 */
void set_name_ob(file file) {
    unsigned long len;
    len = strlen(file->name);
    len = len+EXTENSION_LENGTH;
    file->name_ob = (char*)calloc(1,len);
    if (is_allocation_succeeded(file->name_ob)) {
        strcpy(file->name_ob, file->name);
        strcat(file->name_ob, ".ob");
    }
}

/*
 * Set the name of the file to be the accepted name with the .ent extension
 */
void set_name_ent(file file) {
    unsigned long len;
    len = strlen(file->name);
    len = len+EXTENSION_LENGTH;
    file->name_ent = (char*)calloc(1,len);
    if (is_allocation_succeeded(file->name_ent)) {
        strcpy(file->name_ent, file->name);
        strcat(file->name_ent, ".ent");
    }
}

/*
 * Set the name of the file to be the accepted name with the .ext extension
 */
void set_name_ext(file file) {
    unsigned long len;
    len = strlen(file->name);
    len = len+EXTENSION_LENGTH;
    file->name_ext = (char*)calloc(1,len);
    if (is_allocation_succeeded(file->name_ext)) {
        strcpy(file->name_ext, file->name);
        strcat(file->name_ext, ".ext");
    }
}
/* end of private functions implementation */