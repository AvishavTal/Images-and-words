/*
* Created by Avishav & Sapir on March 1, 2022
*/

#ifndef EX14_LINKED_LIST_H
#define EX14_LINKED_LIST_H

/**
 * representation of list
 */
typedef struct list *list;

/**
 * representation of node
 */
typedef struct node *node;

/**
 * gets list and return the first node in the list
 * @param list required list
 * @return first node of the required list
 */
void* get_head(list list);

/**
 * gets node and return the node's data
 * @param node required node
 * @return the node's data
 */
void* get_node_data(node node);

/**
 * gets node and return the next node
 * @param node required node
 * @return next node
 */
void* get_next_node(node node);

/**
 * This function creates empty list
 * @return empty list
 */
list create_empty_list();

/**
 * This function gets list and data and add new node to the end of the list
 * @param new_data data to enter
 */
void add_to_tail(struct list*, void *new_data);

/**
 * free the memory that the list to_free use, does not free the memory of the data stored in it.
 * @param to_free the required list to delete
 */
void free_list(list to_free);

#endif