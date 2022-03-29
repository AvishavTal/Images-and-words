/*
* Created by avishav on 29.3.2022.
*/

#include "unsigned_long_list.h"
#include "linked_list.h"
#include <stdlib.h>

struct unsigned_long_list{
    list the_list;
    unsigned long size;
};

ul_list init_ul_list(){
    ul_list result;
    result=(ul_list)malloc(sizeof (struct unsigned_long_list));
    result->size=0;
    result->the_list=create_empty_list();
    return result;
}

void append(ul_list to_update,unsigned long new_val){
    unsigned long *new_val_ptr;
    new_val_ptr=(unsigned long *) malloc(sizeof(unsigned long));
    *new_val_ptr=new_val;
    add_to_tail(to_update->the_list,new_val_ptr);
    to_update->size++;
}
unsigned long get_size(ul_list list){
    return list->size;
}
void delete_ul_list(ul_list to_delete){
    node current;
    current=get_head(to_delete->the_list);
    while (current){
        free(get_node_data(current));
        current=get_next_node(current);
    }
    free_list(to_delete->the_list);
    free(to_delete);
}

void get_next_val(ul_list list,unsigned long *dest){
    static node current;
    if(list!=NULL){
        current=get_head(list->the_list);
    }
    if(current!=NULL){
        unsigned long *current_long;
        current_long=get_node_data(current);
        *dest=*current_long;
        current=get_next_node(current);
    }
}