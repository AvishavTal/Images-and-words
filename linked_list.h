//
// Created by Sapir on 28.2.2022.
//

#ifndef EX14_LINKED_LIST_H
#define EX14_LINKED_LIST_H
typedef struct node *node;
typedef struct list *list;
void* get_node_data(node node);
void* get_node_next(node node);
list create_empty_list();
void add_to_tail(struct list*, void *new_data);


void print_names_in_symbols_list(struct list* list);//to delete later
void print_names_in_macros_list(struct list* list);//to delete later
#endif //EX14_LINKED_LIST_H
