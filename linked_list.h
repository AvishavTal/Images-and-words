//
// Created by Sapir on 28.2.2022.
//

#ifndef EX14_LINKED_LIST_H
#define EX14_LINKED_LIST_H
typedef struct node *node;
typedef struct list *list;
void* get_head(list list);
void* get_node_data(node node);
void* get_next_node(node node);
list create_empty_list();
void add_to_tail(struct list*, void *new_data);

/**
 * free the memory that the list to_free use, does not free the memory of the data stored in it.
 * @param to_free
 */
void free_list(list to_free);

#endif /* EX14_LINKED_LIST_H */