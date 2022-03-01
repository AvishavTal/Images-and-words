
#include <stdio.h>
#include <string.h>
#include "operand_table.h"
#define TABLE_SIZE 16
struct operand{
    char *name;
    int funct;
    int opcode;

}operands[]={
        {"mov",0,0},
        {"cmp",0,1},
        {"add",10,2},
        {"sub",11,2},
        {"lea",0,4},
        {"clr",10,5},
        {"not",11,5},
        {"inc",12,5},
        {"dec",13,5},
        {"jmp",10,9},
        {"bne",11,9},
        {"jsr",12,9},
        {"red",0,12},
        {"prn",0,13},
        {"rts",0,14},
        {"stop",0,15}
};


/**
 * check  opname is name of legal operand, if true then funct and opcode get the value of the opname
 * @param opname
 * @param funct
 * @param opcode
 * @return 1 if the table is_legal_operand the opname, 0 otherwise
 */
int is_legal_operand(const char *opname, int *funct, int *opcode){
    int i;
    for ( i = 0; i < TABLE_SIZE; ++i) {
        if (!strcmp(opname, operands[i].name)){
            *funct=operands[i].funct;
            *opcode=operands[i].opcode;
            return 1;
        }
    }
    return 0;
}