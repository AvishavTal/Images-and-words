//
// Created by avishav on 10.3.2022.
//

#include <string.h>
#include "register_table.h"
#include "string_manipulations.h"

#define REG_TABLE_SIZE 16

struct reg {
    char *name;
    int reg_code;
    boolean valid_index :1; /*true if this register can be index, false otherwise*/
};

regyster get_register_by_name(char *name){
    int i;
    static struct reg registers[]={
            {"r0",0,0},
            {"r1",1,0},
            {"r2",2,0},
            {"r3",3,0},
            {"r4",4,0},
            {"r5",5,0},
            {"r6",6,0},
            {"r7",7,0},
            {"r8",8,0},
            {"r9",9,0},
            {"r10",10,1},
            {"r11",11,1},
            {"r12",12,1},
            {"r13",13,1},
            {"r14",14,1},
            {"r15",15,1}
    };
    name=trim_whitespace(name);
    for (i=0 ; i < REG_TABLE_SIZE ; ++i) {
        if(!strcmp(registers[i].name,name)){
            return registers+i;
        }
    }
    return NULL;
}

int get_reg_code(regyster reg){
    return reg->reg_code;
}

boolean get_is_valid_index(regyster reg){
    return reg->valid_index;
}