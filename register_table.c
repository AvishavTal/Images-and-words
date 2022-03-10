//
// Created by avishav on 10.3.2022.
//

#include <string.h>
#include "register_table.h"
#define REG_TABLE_SIZE 16

struct reg {
    char *name;
    int regcode;
}registers[]={
        {"r0",0},
        {"r1",1},
        {"r2",2},
        {"r3",3},
        {"r4",4},
        {"r5",5},
        {"r6",6},
        {"r7",7},
        {"r8",8},
        {"r9",9},
        {"r10",10},
        {"r11",11},
        {"r12",12},
        {"r13",13},
        {"r14",14},
        {"r15",15}
};
regyster get_register_by_name(char *name){
    int i=0;
    for (;i  < REG_TABLE_SIZE; ++i) {
        if(!strcmp(registers[i].name,name)){
            return registers+i;
        }
    }
    return NULL;
}

int get_regcode(regyster register1){
    return register1->regcode;
}