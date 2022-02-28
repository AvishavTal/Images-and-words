//
// Created by avishav on 28.2.2022.
//

#include "symbool.h"
#include "attribute.h"
struct symbol{
    char *name;
    long value;
    long base_address;
    long offset;
    attribute attribute;
};
