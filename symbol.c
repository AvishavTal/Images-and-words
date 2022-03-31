/*
* Created by Avishav & Sapir on March 1, 2022
*/

#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "boolean.h"
#include "system_errors.h"
#include "unsigned_long_list.h"

#define BASE 16

struct symbol{
    char *name;
    unsigned long address;
    struct attr{
        unsigned int is_entry :1;
        unsigned int is_extern :1;
        unsigned int is_data :1;
        unsigned int is_code :1;
    }attribute;

    /*addresses of words requires the base address of the offset of this symbol and the sizes of those arrays*/
    ul_list base_required;
    ul_list offset_required;

};

/**
 * Updates the name of the received symbol
 * @param curr_symbol the needed symbol
 * @param name the wanted name
 */
void set_symbol_name(symbol curr_symbol , char *name);

void print_base_required(FILE *dest, symbol to_print);

void print_offset_required(FILE *dest, symbol to_print);

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
            new_symbol->base_required=init_ul_list();
            new_symbol->offset_required=init_ul_list();
        }
    }
    return new_symbol;
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

boolean is_entry_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_entry;
}

boolean is_extern_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_extern;
}

boolean is_data_symbol(symbol curr_symbol){
    return curr_symbol->attribute.is_data;
}

void delete_symbol(symbol to_delete){
    free(to_delete->name);
    if (is_extern_symbol(to_delete)){
        delete_ul_list(to_delete->base_required);
        delete_ul_list(to_delete->offset_required);
    }
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
    unsigned long offset_required_size,address,i=0;
    offset_required_size=get_size(to_print->offset_required);
    get_next_val(to_print->offset_required,&address);
    for (;i<offset_required_size;++i){
        fprintf(dest,"%s OFFSET %04lu\n",to_print->name,address);
        get_next_val(NULL,&address);
    }
}

void print_base_required(FILE *dest, symbol to_print) {
    unsigned long base_required_size,address,i=0;
    base_required_size=get_size(to_print->base_required);
    get_next_val(to_print->base_required,&address);
    for (;i<base_required_size;++i){
        fprintf(dest,"%s BASE %04lu\n",to_print->name,address);
        get_next_val(NULL,&address);
    }
}
void add_to_base_required(symbol to_update,unsigned long address){
    append(to_update->base_required,address);
}
void add_to_offset_required(symbol to_update,unsigned long address){
    append(to_update->offset_required,address);
}