//
// Created by avishav on 8.3.2022.
//

#include <stdlib.h>
#include "word.h"
#include "ARE.h"
#include "addressing_mode.h"


#define OPCODE_SHIFT 0
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

#define OPCODE_MASK 0777777
#define ARE_MASK 0700000
#define DEST_ADDRESSING_MASK 3
#define DEST_REG_MASK 074
#define SRC_ADDRESSING_MASK 0300
#define SRC_REG_MASK 07400
#define FUNCT_MASK 0170000
#include <stdlib.h>

struct word{
    unsigned long address;
    long the_actual_word;//todo find appropriate name
};

word init_word(){
    word result;
    result=(word) malloc(sizeof(struct word));
    result->the_actual_word=0;
    result->address=0;
    return result;
}

void print_word(FILE *dest, word to_print){
    int a=0,b=0,c=0,d=0,e=0; /*the groups of bits in the special base*/
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
    fprintf(dest,"%04lu ABSOLUTE%03x-B%03x-C%03x-D%03x-EXTERNAL%03x\n",to_print->address,a,b,c,d,e);
}

void set_address(word to_set,unsigned long new_address){
    to_set->address=new_address;
}

void delete_word(word to_delete){
    free(to_delete);
}

void set_are(word to_set, are new_are){
    new_are <<= ARE_SHIFT;
    to_set->the_actual_word |= new_are;
}

void set_opcode(word to_set,int new_opcode){
    new_opcode=1<<new_opcode;
    to_set->the_actual_word |= new_opcode;
}

void set_funct(word to_set,int new_funct){
    new_funct<<=FUNCT_SHIFT;
    to_set->the_actual_word|=new_funct;
}

void set_dest_register(word to_set,int reg_num){
    reg_num<<=DEST_REG_SHIFT;
    to_set->the_actual_word|=reg_num;
}

void set_dest_addressing(word to_set, addressing_mode dest_addressing){
    dest_addressing<<=DEST_ADDRESSING_SHIFT;
    to_set->the_actual_word|=dest_addressing;
}

void set_src_register(word to_set,int reg_num){
    reg_num<<=SRC_REG_SHIFT;
    to_set->the_actual_word|=reg_num;
}

void set_src_addressing(word to_set, addressing_mode src_addressing){
    src_addressing<<=SRC_ADDRESSING_SHIFT;
    to_set->the_actual_word|=src_addressing;
}
void set_immediate(word to_set,int immediate){
    to_set->the_actual_word|=immediate;
}

void set_data(word to_set,long new_data){
    to_set->the_actual_word=new_data;
}

