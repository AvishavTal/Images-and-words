//
// Created by avishav on 28.2.2022.
//

#include "linked_list.h"
#include "macro.h"
#include "symbool.h"
typedef union data{
    macro macro;
    symbol symbol;
    char *line;
}data;

typedef struct node{
    data data;
    struct node *next;
}node;

