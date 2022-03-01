//
// Created by avishav on 28.2.2022.
//
#include<stdio.h>
#include<stdlib.h>

#include "linked_list.h"
#include "macro.h"
#include "symbol.h"

typedef union data{
    macro macro;
    symbol symbol;
    char *line;
}data;

typedef struct node{
    symbol data;// Any data type can be stored in this node
    struct node *next;
}node;


/* Function to add a node at the beginning of Linked List.
   This function expects a pointer to the data to be added
   and size of the data type */
void push(node** head_ref, symbol new_data)
{
    // Allocate memory for node
    struct node* new_node = (node*)malloc(sizeof(struct node));

    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    printf("1\n");
    struct node *start = NULL;
    symbol new_symbol = init_symbol();
    char *name1 = "sapir";
    printf("2\n");
    update_symbol(new_symbol, name1, 5, 4, 3, NULL);
    printf("3\n");
    push(&start, new_symbol);
    printf("4\n");

    return 0;
}
