//
// Created by avishav on 10.3.2022.
//

#ifndef EX14_DATA_IMAGE_H
#define EX14_DATA_IMAGE_H
#include <stdio.h>
typedef struct image *data_image;
data_image init_data_image();
void add_data(data_image image, long address, long new_data);
void print_data(FILE *dest,data_image image);
void delete_data(data_image to_delete);
void update_addresses(data_image image,long final_ic);
#endif //EX14_DATA_IMAGE_H
