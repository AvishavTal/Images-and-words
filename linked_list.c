/*
* Created by Avishav & Sapir on March 1, 2022
*/

#include<stdio.h>
#include<stdlib.h>
#include "system_errors.h"
#include "linked_list.h"

struct list {
    struct node *head;
    struct node *tail;
};

struct node {
    void *data; /* Any data type can be stored in this node */
    struct node *next;
};


/* public functions implementation */

void* get_head(list list) {
    return list->head;
}

void* get_node_data(node node) {
    return node->data;
}

void* get_next_node(node node) {
    return node->next;
}

list create_empty_list() {
    struct list *new_list;
    new_list = (struct list*)malloc(sizeof(struct list));
    if (is_allocation_succeeded(new_list)) {
        new_list->head = NULL;
        new_list->tail = NULL;
    }
    return new_list;
}

void add_to_tail(struct list* list, void *new_data) {
    /* Allocate memory for node */
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    if (is_allocation_succeeded(new_node)) {
        /* append the received data to the new node */
        new_node->data = new_data;
        new_node->next = NULL;

        /* if this node is the first node in the list - add the node as head and tail */
        if (list->head == NULL) {
            list->head = new_node;
            list->tail = new_node;
        } else { /* this node is NOT the first node in the list - add the new node to the end of the list */
            list->tail->next = new_node;
            list->tail = new_node;
        }
    }
}

void free_list(list to_free) {
    node current,next;
    current = to_free->head;
    next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(to_free);
}

/* end of public functions implementation */