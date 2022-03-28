/*
** Created by Avishav & Sapir on March 1,2022
*/

#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "boolean.h"
#include "system_errors.h"
#include "linked_list.h"

#define BASE 16

struct symbol{
    char *name;
    unsigned long address;
    struct attr{
        boolean is_entry :1;
        boolean is_extern :1;
        boolean is_data :1;
        boolean is_code :1;
    }attribute;

    /*addresses of words requires the base address of the offset of this symbol and the sizes of those arrays*/
    list base_required;
    list offset_required;

};

void print_base_required(FILE *dest, symbol to_print);

void print_offset_required(FILE *dest, symbol to_print);

symbol init_symbol(){
    symbol new_symbol;
    new_symbol=(symbol)calloc(1,sizeof(struct symbol));
    if(is_allocation_succeeded(new_symbol)) {
        new_symbol->name = NULL;
        new_symbol->address = 0;
        new_symbol->attribute.is_entry = false;
        new_symbol->attribute.is_extern = false;
        new_symbol->attribute.is_data = false;
        new_symbol->attribute.is_code = false;
    }
    return new_symbol;
}

symbol init_symbol_with_values(char *name, unsigned long address, boolean is_entry, boolean is_extern, boolean is_data, boolean is_code){
    symbol new_symbol;
    new_symbol=(symbol)malloc(sizeof(struct symbol));
    if(is_allocation_succeeded(new_symbol)) {
        set_symbol_name(new_symbol,name);
        new_symbol->address = address;
        new_symbol->attribute.is_entry = is_entry;
        new_symbol->attribute.is_extern = is_extern;
        new_symbol->attribute.is_data = is_data;
        new_symbol->attribute.is_code = is_code;
        if (is_extern){
            new_symbol->base_required=create_empty_list();
            new_symbol->offset_required=create_empty_list();
        }
    }
    return new_symbol;
}

void update_symbol(symbol curr_symbol, char* name, unsigned long address){
    set_symbol_name(curr_symbol,name);
    set_symbol_address(curr_symbol, address);
}

char* get_symbol_name(symbol curr_symbol){
    return curr_symbol->name;
}

void set_symbol_name(symbol curr_symbol , char *name){
    char *new_name;
    new_name=(char *) malloc(strlen(name)+1);
    if(is_allocation_succeeded(new_name)) {
        strcpy(new_name, name);
        curr_symbol->name = new_name;
    }
}

unsigned long get_symbol_address(symbol curr_symbol){
    return curr_symbol->address;
}

void set_symbol_address(symbol curr_symbol , unsigned long address){
    curr_symbol->address=address;
}

unsigned long get_symbol_base_address(symbol curr_symbol){
    return (curr_symbol->address / BASE)*BASE;
}

unsigned long get_symbol_offset(symbol curr_symbol){
    return curr_symbol->address % BASE;
}

void mark_entry(symbol to_mark){
    to_mark->attribute.is_entry = true;
}

void mark_extern(symbol to_mark){
    to_mark->attribute.is_extern = true;
}

void mark_code(symbol to_mark){
    to_mark->attribute.is_code = true;
}

void mark_data(symbol to_mark){
    to_mark->attribute.is_data = true;
}

boolean get_is_entry_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_entry;
}

boolean get_is_extern_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_extern;
}

boolean get_is_code_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_code;
}

boolean get_is_data_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_data;
}

void delete_symbol(symbol to_delete){
    free(to_delete->name);
    free(to_delete);
}

void print_entry_symbol(FILE *dest,symbol to_print){
    char *name;
    unsigned long address,offset;
    name= get_symbol_name(to_print);
    address= get_symbol_base_address(to_print);
    offset= get_symbol_offset(to_print);
    fprintf(dest,"%s,%04ld,%04ld\n",name,address,offset);
}
void print_extern_symbol(FILE *dest,symbol to_print){
    print_base_required(dest,to_print);
    print_offset_required(dest,to_print);
}

void print_offset_required(FILE *dest, symbol to_print) {
    node current;
    current= get_head(to_print->offset_required);
    while (current){
        unsigned long *address;
        address= get_node_data(current);
        fprintf(dest,"%s OFFSET %04lu\n",to_print->name,*address);
        current= get_next_node(current);
    }
}

void print_base_required(FILE *dest, symbol to_print) {
    node current;
    current= get_head(to_print->base_required);
    while (current){
        unsigned long *address;
        address= get_node_data(current);
        fprintf(dest,"%s BASE %04lu\n",to_print->name,*address);
        current= get_next_node(current);
    }
}
void add_to_base_required(symbol to_update,unsigned long address){
    unsigned long *new_val_ptr;
    new_val_ptr=(unsigned long *) malloc(sizeof(unsigned long));
    *new_val_ptr=address;
    add_to_tail(to_update->base_required,new_val_ptr);
}
void add_to_offset_required(symbol to_update,unsigned long address){
    unsigned long *new_val_ptr;
    new_val_ptr=(unsigned long *) malloc(sizeof(unsigned long));
    *new_val_ptr=address;
    add_to_tail(to_update->offset_required,new_val_ptr);
}