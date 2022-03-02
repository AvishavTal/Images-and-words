//
// Created by avishav on 28.2.2022.
//
#include<stdio.h>
#include<stdlib.h>

#include "linked_list.h"
#include "macro.h"
#include "symbol.h"

typedef struct node{
    void *data;// Any data type can be stored in this node
    struct node *next;
}node;

void push(node** head_ref, void *new_data, size_t data_size)
{
    // Allocate memory for node
    struct node* new_node = (node*)malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

node* newNode(int data)
{
    // allocate a new node in a heap using `malloc()` and set its data
    node* node = (node*)malloc(sizeof(node));
    node->data = data;

    // set the `.next` pointer of the new node to point to null
    node->next = NULL;

    return node;
}

int main() {
    printf("1\n");
    struct node *start = NULL;
    symbol new_symbol = init_symbol();
    char *name1 = "sapir";
    printf("2\n");
    update_symbol(new_symbol, name1, 5, 4, 3, NULL);
    printf("3\n");
    //push(&start, new_symbol, sizeof(symbol));
    node *new_int_node =  newNode(5) ;

    printf("4");
    //printf("start data = %s\n",start->data);
    //printf("name = %l\n", get_value(start->data));

    return 0;
}