//
// Created by Sapir on 28.2.2022.
//
#include<stdio.h>
#include<stdlib.h>

#include "linked_list.h"
#include "macro.h"
#include "symbol.h"

struct node{
    void *data;// Any data type can be stored in this node
    struct node *next;
};

void* get_node_data(node node){
    return node->data;
}

void* get_node_next(node node){
    return node->next;
}

void add_to_tail(struct node** head, struct node** tail, void *new_data)
{
    // Allocate memory for node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    //Check if the allocation failed
    if(new_node == NULL){
        printf("Unable to allocate memory for new node\n");
        exit(-1);
    }

    //append the new node to the end of the list
    new_node->data = new_data;
    new_node->next = NULL;

    //if this node is the first node in the list
    if ((*head) == NULL) {
        (*head) = new_node;
        (*tail) = new_node;
    }
    else { // this node is NOT the first node in the list
        (*tail)->next = new_node;
        (*tail) = new_node;
    }
}


void print_names_in_symbols_list(struct node** head, struct node** tail){//to delete later
    printf("print_names_in_symbols_list");

    struct node *temp = (*head);
    if(temp == NULL){
        printf("this list is empty");
    }
    else if((*head) == (*tail)){
        printf("name1 = %s\n", get_symbol_name(((*head)->data)));
    }
    else{
        while(temp != NULL){
            printf("name1 = %s\n", get_symbol_name(((temp)->data)));
            temp=temp->next;
        }
    }
}

void print_names_in_macros_list(struct node** head, struct node** tail){//to delete later
    printf("print_names_in_macros_list");
    struct node *temp = (*head);
    if(temp == NULL){
        printf("this list is empty");
    }
    else if((*head) == (*tail)){
        printf("name2 = %s\n", get_macro_name(((*head)->data)));
    }
    else{
        while(temp != NULL){
            printf("name2 = %s\n", get_macro_name(((temp)->data)));
            temp=temp->next;
        }
    }
}


