//
// Created by Sapir on 28.2.2022.
//
#include<stdio.h>
#include<stdlib.h>

#include "linked_list.h"
//#include "macro.h"
#include "symbol.h"

typedef struct node{
    void *data;// Any data type can be stored in this node
    struct node *next;
}node;


void add_to_tail(node** head, node** tail, void *new_data)
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
void print_names_in_symbols_list(node** head, node** tail){
    struct node *temp = (*head);
    if(temp == NULL){
        printf("this list is empty");
    }
    else if((*head) == (*tail)){
        printf("name1 = %s\n",get_name(((*head)->data)));
    }
    else{
        while(temp != NULL){
            printf("name2 = %s\n",get_name(((temp)->data)));
            temp=temp->next;
        }
    }
}

int main() {

    //list of symbols
    /*
    struct node * head = NULL;
    struct node * tail = NULL;

    symbol new_symbol = init_symbol();
    char *name1 = "Sapir";
    update_symbol(new_symbol, name1, 5, 4, 3, NULL);
    add_to_tail(&head, &tail, new_symbol);

    symbol new_symbol2 = init_symbol();
    char *name2 = "Avishav";
    update_symbol(new_symbol2, name2, 5, 4, 3, NULL);
    add_to_tail(&head, &tail, new_symbol2);

     print_names_in_symbols_list(&head,&tail);
     */
    return 0;
}