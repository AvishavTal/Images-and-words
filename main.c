#include <stdio.h>
#include "linked_list.h"
#include "symbol.h"
#include "macro.h"

void check_list_of_symbols();//to delete later
void check_list_of_macros();//to delete later

int main(int argc,char **argv){

    check_list_of_symbols();//to delete later
    check_list_of_macros();//to delete later

    return 0;
}

void check_list_of_symbols(){//to delete later
    //list of symbols

    list symbol_list = create_empty_list();
    symbol new_symbol = init_symbol();
    char *name1 = "symbol1";
    update_symbol(new_symbol, name1, 5, 4, 3, NULL);
    add_to_tail(symbol_list, new_symbol);

    symbol new_symbol2 = init_symbol();
    char *name2 = "symbol2";
    update_symbol(new_symbol2, name2, 5, 4, 3, NULL);
    add_to_tail(symbol_list, new_symbol2);

    print_list(symbol_list);
}

void check_list_of_macros(){//to delete later
    //list of symbols

    list macro_list = create_empty_list();

    macro new_macro = init_macro();
    char *name1 = "macro1";
    set_macro_name(new_macro, name1);

    add_to_tail(macro_list, new_macro);

    macro new_macro2 = init_macro();
    char *name2 = "macro2";
    set_macro_name(new_macro2, name2);

    add_to_tail(macro_list, new_macro2);
    print_list(macro_list);
}