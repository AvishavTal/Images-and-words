/*
* Created by Avishav & Sapir on March 2, 2022
*/

#include <stdlib.h>
#include <string.h>
#include "macro_table.h"
#include "linked_list.h"
#include "system_errors.h"

struct macro_table {
    list table;
};


/* public functions implementation */
macro_table init_macro_table() {
    macro_table result;
    result = (macro_table) malloc(sizeof(struct macro_table));
    if (is_allocation_succeeded(result)) {
        result->table = create_empty_list();
    }
    return result;
}

macro get_macro_by_name(macro_table macros, char *name) {
    node current_node = get_head(macros->table);
    macro current_macro,result = NULL;
    while ((current_node != NULL) && (result == NULL)) {
        current_macro = get_node_data(current_node);
        if (!strcmp(name, get_macro_name(current_macro))) {
            result = current_macro;
        }
        current_node = get_next_node(current_node);
    }
    return result;
}

void push_macro(macro_table table, macro new_macro) {
    add_to_tail(table->table,new_macro);
}

void delete_macro_table(macro_table to_delete) {
    node current;
    current = get_head(to_delete->table);
    while (current) {
        delete_macro((macro)get_node_data(current));
        current = get_next_node(current);
    }
    free_list(to_delete->table);
    free(to_delete);
}
/* end of public functions implementation */