/*
* Created by Avishav & Sapir on March 8, 2022
*/

#include <stdlib.h>
#include "word.h"
#include "ARE.h"
#include "system_errors.h"
#include "addressing_mode.h"

#define DEST_ADDRESSING_SHIFT 0
#define DEST_REG_SHIFT 2
#define SRC_ADDRESSING_SHIFT 6
#define SRC_REG_SHIFT 8
#define FUNCT_SHIFT 12
#define ARE_SHIFT 16

#define A_SHIFT 16
#define B_SHIFT 12
#define C_SHIFT 8
#define D_SHIFT 4
#define E_SHIFT 0
#define MASK 017

#define IMMEDIATE_MASK 0xffff

struct word{
    unsigned long address;
    unsigned long the_actual_word;
};

word init_word(){
    word result;
    result=(word) malloc(sizeof(struct word));
    if(is_allocation_succeeded(result)) {
        result->the_actual_word = 0;
        result->address = 0;
    }
    return result;
}


void print_word(FILE *dest, word to_print){
    unsigned int a,b,c,d,e;
    a=to_print->the_actual_word>>A_SHIFT;
    b=to_print->the_actual_word>>B_SHIFT;
    c=to_print->the_actual_word>>C_SHIFT;
    d=to_print->the_actual_word>>D_SHIFT;
    e=to_print->the_actual_word>>E_SHIFT;
    a&=MASK;
    b&=MASK;
    c&=MASK;
    d&=MASK;
    e&=MASK;
    fprintf(dest,"%04lu A%x-B%x-C%x-D%x-E%x\n",to_print->address,a,b,c,d,e);
}


void set_address(word to_set,unsigned long new_address){
    to_set->address=new_address;
}

unsigned long get_address(word word1){
    return word1->address;
}

void delete_word(word to_delete){
    free(to_delete);
}

void set_are(word to_set, are new_are){
    unsigned int temp;
    temp=new_are;
    temp <<= ARE_SHIFT;
    to_set->the_actual_word |= temp;
}

void set_opcode(word to_set, unsigned int new_opcode){
    new_opcode=1<<new_opcode;
    to_set->the_actual_word |= new_opcode;
}

void set_funct(word to_set, unsigned int new_funct){
    new_funct<<=FUNCT_SHIFT;
    to_set->the_actual_word|=new_funct;
}

void set_dest_register(word to_set, unsigned int reg_num){
    reg_num<<=DEST_REG_SHIFT;
    to_set->the_actual_word|=reg_num;
}

void set_dest_addressing(word to_set, addressing_mode dest_addressing){
    unsigned long temp;
    temp=dest_addressing;
    temp<<=DEST_ADDRESSING_SHIFT;
    to_set->the_actual_word|=temp;
}

void set_src_register(word to_set, unsigned int reg_num){
    reg_num<<=SRC_REG_SHIFT;
    to_set->the_actual_word|=reg_num;
}

void set_src_addressing(word to_set, addressing_mode src_addressing){
    unsigned long temp;
    temp=src_addressing;
    temp<<=SRC_ADDRESSING_SHIFT;
    to_set->the_actual_word|=temp;
}

void set_immediate(word to_set, unsigned int immediate){
    immediate&=IMMEDIATE_MASK;
    to_set->the_actual_word|=immediate;
}