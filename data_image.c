//
// Created by avishav on 10.3.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "data_image.h"
#include "word.h"
#include "linked_list.h"
#include "parser.h"
#include <ctype.h>
#include "string_manipulations.h"

struct image{
    list words;
};


data_image init_data_image(){
    data_image result;
    result=(data_image) malloc(sizeof(struct image));
    result->words=create_empty_list();
    return result;
}


void add_data(data_image image, unsigned long address, unsigned long new_data){
    word new_word;
    new_word=init_word();
    set_address(new_word,address);
    set_data(new_word,new_data);
    add_to_tail(image->words,new_word);
}


void print_data(FILE *dest,data_image image){
    node current_node;
    current_node=get_head(image->words);
    while (current_node){
        print_word(dest,get_node_data(current_node));
        current_node=get_next_node(current_node);
    }
}


void delete_data(data_image to_delete){
    node current_node;
    current_node= get_head(to_delete->words);
    while (current_node){
        delete_word(get_node_data(current_node));
        current_node=get_next_node(current_node);
    }
}
void update_addresses(data_image image,long final_ic){
    node current_node;
    current_node=get_head(image->words);
    while (current_node){
        long new_address,old_address;
        word to_update;
        to_update= get_node_data(current_node);
        old_address= get_address(to_update);
        new_address=old_address+final_ic;
        set_address(to_update,new_address);
        current_node=get_next_node(current_node);
    }
}

void add_string(data_image image, unsigned long address, char *new_string, int *n_words, error *err) {
    int i=0;
    new_string= trim_whitespace(new_string);
    *n_words= strlen(new_string)-1;
    if(!is_string(new_string)){
        *err=ILLEGAL_STRING_SYNTAX;
    } else{
        for (; i <*n_words ; i++) {
            if (isprint(new_string[i])){
                add_data(image,address,new_string[i]);
            } else{
                *err=ILLEGAL_STRING;
            }

        }
    }
}

void add_data_line(data_image image, unsigned long address, char *line, int *n_words, error *err) {

}
