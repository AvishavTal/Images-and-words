//
// Created by avishav on 1.3.2022.
//

#include <stdlib.h>
#include "obj_line.h"
struct obj_line{
    long address;
    unsigned int a :4;
    unsigned int b :4;
    unsigned int c :4;
    unsigned int d :4;
    unsigned int e :4;
};
ob_line init_lint(){
    ob_line result=(ob_line)malloc(sizeof(struct obj_line));
    if (result){
        result->address=0;
        result->a=0;
        result->b=0;
        result->c=0;
        result->d=0;
        result->e=0;
    }
    return result;
}
long get_address(ob_line line){
    return line->address;
}
void set_address(ob_line line, long new_address){
    line->address=new_address;
}

unsigned int get_a(ob_line line){
    return line->a;
}
unsigned int get_b(ob_line line){
    return line->b;
}
unsigned int get_c(ob_line line){
    return line->c;
}
unsigned int get_d(ob_line line){
    return line->d;
}
unsigned int get_e(ob_line line){
    return line->e;
}
void set_a(ob_line line, unsigned int new_a){
    line->a=new_a;
}
void set_b(ob_line line, unsigned int new_b){
    line->b=new_b;
}
void set_c(ob_line line, unsigned int new_c){
    line->c=new_c;
}
void set_d(ob_line line, unsigned int new_d){
    line->d=new_d;
}
void set_e(ob_line line, unsigned int new_e){
    line->e=new_e;
}
