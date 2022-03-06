#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "symbol.h"
#include "macro.h"

void check_list_of_symbols();//to delete later
void check_list_of_macros();//to delete later

#include "file.h"
#include "pre_assembler.h"
#include "first_scan.h"
#include "seconde_scan.h"

file *init_files(file *files, int n_files, char **names);

void run_assembler(file *files, int n_files);

int main(int argc, char **argv){
    file *files=NULL;
    files=init_files(files,--argc,++argv);
    run_assembler(files,argc);
    check_list_of_symbols();//to delete later
    check_list_of_macros();//to delete later

    return 0;
}

void run_assembler(file *files, int n_files) {
    int i=0;
    for (; i < n_files; ++i) {
        if (files[i]){

        }
    }
}

file *init_files(file *files, int n_files, char **names) {
    int i=0;
    files=(file *) malloc(sizeof(file)*n_files);
    for ( ; i < n_files; ++i) {
        init_file(names[i]);
    }
    return files;
}

void check_list_of_symbols(){//to delete later
    //list of symbols

    node head = NULL;
    node tail = NULL;
    //node temp;

    symbol new_symbol = init_symbol();
    char *name1 = "symbol1";
    update_symbol(new_symbol, name1, 5, 4, 3, NULL);
    add_to_tail(&head, &tail, new_symbol);

    symbol new_symbol2 = init_symbol();
    char *name2 = "symbol2";
    update_symbol(new_symbol2, name2, 5, 4, 3, NULL);

    add_to_tail(&head, &tail, new_symbol2);
    symbol symbol1= get_node_next((node )new_symbol);
    char *name8=get_symbol_name(symbol1);
    printf("name8: %s\n",name8);
    print_names_in_symbols_list(&head,&tail);
}

void check_list_of_macros(){//to delete later
    //list of symbols

    node head = NULL;
    node tail = NULL;
    //node temp;

    macro new_macro = init_macro();
    char *name1 = "macro1";
    set_macro_name(new_macro, name1);

    add_to_tail(&head, &tail, new_macro);

    macro new_macro2 = init_macro();
    char *name2 = "macro2";
    set_macro_name(new_macro2, name2);

    add_to_tail(&head, &tail, new_macro2);
    print_names_in_macros_list(&head,&tail);
}