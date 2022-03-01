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
    void *data;// Any data type can be stored in this node
    struct node *next;
}node;


/* Function to add a node at the beginning of Linked List.
   This function expects a pointer to the data to be added
   and size of the data type */
void push(node** head_ref, void *new_data, size_t data_size)
{
    // Allocate memory for node
    node* new_node = (node*)malloc(sizeof(node));

    // Allocate memory for data
    new_node->data  = malloc(data_size);
    new_node->next = (*head_ref);

    // Copy contents of new_data to newly allocated memory.
    // Assumption: char takes 1 byte.
    int i;
    for (i=0; i<data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

    // Change head pointer as new node is added at the beginning
    (*head_ref)    = new_node;
}

int main() {
    struct node *start = NULL;
    symbol new_symbol = init_symbol();
    char *name1 = "sapir";
    update_symbol(new_symbol, name1, 5, 4, 3, NULL);
    push(&start, new_symbol, sizeof(symbol));

    //printf("start data = %s\n",start->data);
    printf("name = %s\n", get_name(start->data));

    return 0;
}

/* Function to print nodes in a given linked list. fpitr is used
   to access the function to be used for printing current node data.
   Note that different data types need different specifier in printf() */
/*
void printList(node *node, void (*fptr)(void *))
{
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}

// Function to print an integer
void printInt(void *n)
{
    printf(" %d", *(int *)n);
}

// Function to print a float
void printFloat(void *f)
{
    printf(" %f", *(float *)f);
}
*/