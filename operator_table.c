
#include <stdio.h>
#include <string.h>
#include "operator_table.h"
#include "addressing_mode.h"
#define TABLE_SIZE 16
#define NUMBER_OF_ADDRESSING_METHODS 4
struct allowed_addressing{
    unsigned int immediate :1;
    unsigned int direct :1;
    unsigned int index :1;
    unsigned int register_direct :1;
};

struct operator{
    char *name;
    int funct;
    int opcode;
    int num_of_operands;
    struct allowed_addressing source;
    struct allowed_addressing dest;

    /*addressing modes allowd fo each argument*/
//    addressing_mode source_addressing[NUMBER_OF_ADDRESSING_METHODS];
//    addressing_mode dest_addressing[NUMBER_OF_ADDRESSING_METHODS];

}operators[]={
        {"mov",0,0,2,{1,1,1,1},{0,1,1,1}},//source allowed methods{IMMEDIATE,DIRECT,INDEX,REGISTER_DIRECT},dest allowed methods{DIRECT,INDEX,REGISTER_DIRECT}
        {"cmp",0,1,2,{1,1,1,1},{1,1,1,1}},//{IMMEDIATE,DIRECT,INDEX,REGISTER_DIRECT},{IMMEDIATE,DIRECT,INDEX,REGISTER_DIRECT}
        {"add",10,2,2,{1,1,1,1},{0,1,1,1}},//{IMMEDIATE,DIRECT,INDEX,REGISTER_DIRECT},{DIRECT,INDEX,REGISTER_DIRECT}
        {"sub",11,2,2,{1,1,1,1},{0,1,1,1}},//{IMMEDIATE,DIRECT,INDEX,REGISTER_DIRECT},{DIRECT,INDEX,REGISTER_DIRECT}
        {"lea",0,4,2,{0,1,1,0},{0,1,1,1}},//{DIRECT,INDEX},{DIRECT,INDEX,REGISTER_DIRECT}
        {"clr",10,5,1,{0,0,0,0},{0,1,1,1}},//{DIRECT,INDEX,REGISTER_DIRECT}
        {"not",11,5,1,{0,0,0,0},{0,1,1,1}},//{DIRECT,INDEX,REGISTER_DIRECT}
        {"inc",12,5,1,{0,0,0,0},{0,1,1,1}},//{DIRECT,INDEX,REGISTER_DIRECT}
        {"dec",13,5,1,{0,0,0,0},{0,1,1,1}},//{DIRECT,INDEX,REGISTER_DIRECT}
        {"jmp",10,9,1,{0,0,0,0},{0,1,1,0}},//{DIRECT,INDEX}
        {"bne",11,9,1,{0,0,0,0},{0,1,1,0}},//{DIRECT,INDEX}
        {"jsr",12,9,1,{0,0,0,0},{0,1,1,0}},//{DIRECT,INDEX}
        {"red",0,12,1,{0,0,0,0},{0,1,1,1}},//{DIRECT,INDEX,REGISTER_DIRECT}
        {"prn",0,13,1,{0,0,0,0},{1,1,1,1}},//{IMMEDIATE,DIRECT,INDEX,REGISTER_DIRECT}
        {"rts",0,14,0,{0,0,0,0},{0,0,0,0}},
        {"stop",0,15,0,{0,0,0,0},{0,0,0,0}}
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
 * check  opname is name of legal operand, if true then funct and opcode get the address of the opname
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