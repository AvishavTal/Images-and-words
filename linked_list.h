//
// Created by Sapir on 28.2.2022.
//

#ifndef EX14_LINKED_LIST_H
#define EX14_LINKED_LIST_H
typedef struct node *node;
void* get_node_data(node node);
void* get_node_next(node node);
void add_to_tail(struct node** head, struct node** tail, void *new_data);
void print_names_in_symbols_list(struct node** head, struct node** tail);
#endif //EX14_LINKED_LIST_H
