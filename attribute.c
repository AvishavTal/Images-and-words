//
// Created by avishav on 28.2.2022.
//

#include "attribute.h"
struct attribute{
    unsigned int is_entry :1;
    unsigned int is_extern :1;
    unsigned int is_data :1;
    unsigned int is_code :1;
};