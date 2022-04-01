/*
* Created by Avishav & Sapir on March 9, 2022
*/

#include <stdlib.h>
#include "macro.h"
#include "macro_body.h"
#include "system_errors.h"
#include "string_manipulations.h"

struct macro {
    char *name;
    macro_body body;
};


/* public functions implementation */
macro init_macro() {
    macro new_macro;
    new_macro = (macro)malloc(sizeof(struct macro));
    if (is_allocation_succeeded(new_macro)) {
        new_macro->name = NULL;
        new_macro->body = init_body();
    }
    return new_macro;
}

char* get_macro_name(macro macro) {
    return macro->name;
}

void set_macro_name(macro macro, char *name) {
    trim_whitespace(name);
    macro->name = (char*)malloc(strlen(name)+1);
    if (is_allocation_succeeded( macro->name)) {
        strcpy(macro->name, name);
    }
}

void append_line(macro macro, char *line) {
    append_line_to_body(macro->body,line);
}

void delete_macro(macro to_delete) {
    free(to_delete->name);
    delete_body(to_delete->body);
    free(to_delete);
}

void macro_call(FILE *dest,macro to_print) {
    print_body(dest,to_print->body);
}
/* end of public functions implementation */