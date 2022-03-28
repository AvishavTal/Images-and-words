//
// Created by Sapir on 28.2.2022.
//
#include<stdio.h>
#include<stdlib.h>

#include "linked_list.h"

struct list{
    struct node *head;
    struct node *tail;
};

struct node{
    void *data;/* Any data type can be stored in this node */
    struct node *next;
};

void* get_head(list list){
    return list->head;
}

void* get_node_data(node node){
    return node->data;
}

void* get_next_node(node node){
    return node->next;
}

list create_empty_list(){
    struct list *new_list = (struct list*)malloc(sizeof(struct list));
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

void add_to_tail(struct list* list, void *new_data){
    /* Allocate memory for node */
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    /* Check if the allocation failed */
    if(new_node == NULL){
        printf("Unable to allocate memory for new node\n");
        exit(-1);
    }

    /* append the received data to the new node */
    new_node->data = new_data;
    new_node->next = NULL;

    /* if this node is the first node in the list - add the node as head and tail */
    if(list->head == NULL){
        list->head = new_node;
        list->tail = new_node;
    }
    else { /* this node is NOT the first node in the list - add the new node to the end of the list */
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

//todo - add free function for nodes and data - remember data in data (like body in macro)