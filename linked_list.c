//
// Created by Sapir on 28.2.2022.
//
#include<stdio.h>
#include<stdlib.h>

#include "linked_list.h"
#include "macro.h" //to delete later
#include "symbol.h" //to delete later

struct list{
    struct node *head;
    struct node *tail;
};

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

list create_empty_list(){
    struct list *new_list = (struct list*)malloc(sizeof(struct list));
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

void add_to_tail(struct list* list, void *new_data){

    // Allocate memory for node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    //Check if the allocation failed
    if(new_node == NULL){
        printf("Unable to allocate memory for new node\n");
        exit(-1);
    }

    //append the accepted data to the new node
    new_node->data = new_data;
    new_node->next = NULL;

    //if this node is the first node in the list
    if(list->head == NULL){
        list->head = new_node;
        list->tail = new_node;
    }
    else { // this node is NOT the first node in the list - add the new node to the end of the list
        list->tail->next = new_node;
        list->tail = new_node;
    }
}
/*
void free_list(list list){

    struct node *temp = list->head;
    while(temp!=NULL){

    }
}*/


void print_names_in_symbols_list(struct list* list){//to delete later
    printf("print_names_in_symbols_list\n");

    struct node *temp = list->head;
    if(temp == NULL){
        printf("this list is empty\n");
    }
    else if(list->head == list->tail){
        printf("name1 = %s\n", get_symbol_name(list->head->data));//((*head)->data)));
    }
    else{
        while(temp != NULL){
            printf("name1 = %s\n", get_symbol_name((temp->data)));
            temp=temp->next;
        }
    }
}

void print_names_in_macros_list(struct list* list){//to delete later
    printf("print_names_in_macros_list\n");

    struct node *temp = list->head;
    if(temp == NULL){
        printf("this list is empty\n");
    }
    else if(list->head == list->tail){
        printf("name2 = %s\n", get_macro_name(list->head->data));//((*head)->data)));
    }
    else{
        while(temp != NULL){
            printf("name2 = %s\n", get_macro_name((temp->data)));
            temp=temp->next;
        }
    }
}