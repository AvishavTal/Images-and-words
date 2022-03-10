
#include <stdio.h>
#include <string.h>
#include "operator_table.h"
#define TABLE_SIZE 16
struct operator{
    char *name;
    int funct;
    int opcode;
    int num_of_operands;

}operators[]={
        {"mov",0,0,2},
        {"cmp",0,1,2},
        {"add",10,2,2},
        {"sub",11,2,2},
        {"lea",0,4,2},
        {"clr",10,5,1},
        {"not",11,5,1},
        {"inc",12,5,1},
        {"dec",13,5,1},
        {"jmp",10,9,1},
        {"bne",11,9,1},
        {"jsr",12,9,1},
        {"red",0,12,1},
        {"prn",0,13,1},
        {"rts",0,14,0},
        {"stop",0,15,0}
};

operator get_operator_by_mame(char *name){
    int i=0;
    operator result=NULL;
    for ( ; i < TABLE_SIZE; ++i) {
        if (!strcmp(name,operators[i].name)){
            result = operators+i;
        }
    }
    return result;
}

int get_opcode(operator op){
    return op->opcode;
}
int get_funct(operator op){
    return op->funct;
}
int get_n_operands(operator op){
    return op->num_of_operands;
}

/**
 * check  opname is name of legal operand, if true then funct and opcode get the value of the opname
 * @param opname
 * @param funct
 * @param opcode
 * @return 1 if the marcos is_legal_operator the opname, 0 otherwise
 */
int is_legal_operator(const char *opname, int *funct, int *opcode){
    int i;
    for ( i = 0; i < TABLE_SIZE; ++i) {
        if (!strcmp(opname, operators[i].name)){
            *funct=operators[i].funct;
            *opcode=operators[i].opcode;
            return 1;
        }
    }
    return 0;
}