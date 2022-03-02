#include <stdio.h>
#include "linked_list.h"
#include "symbol.h"

int main() {

    //list of symbols

     node *head = NULL;
     node *tail = NULL;

    symbol new_symbol = init_symbol();
    char *name1 = "Sapir";
    update_symbol(new_symbol, name1, 5, 4, 3, NULL);
    add_to_tail(&head, &tail, new_symbol);

    symbol new_symbol2 = init_symbol();
    char *name2 = "Avishav";
    update_symbol(new_symbol2, name2, 5, 4, 3, NULL);
    add_to_tail(&head, &tail, new_symbol2);

     print_names_in_symbols_list(&head,&tail);

    return 0;
}