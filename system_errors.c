/*
* Created by Avishav & Sapir on March 15, 2022
*/

#include <stdlib.h>
#include "boolean.h"
#include "system_errors.h"

#define ALLOCATION_EXIT_CODE -1
#define OPEN_FILE_EXIT_CODE -2

boolean is_allocation_succeeded(void* pointer){
    if(pointer == NULL){
        fprintf( stderr, "Unable to allocate memory\n");
        exit(ALLOCATION_EXIT_CODE);
    }
    return true;
}

boolean is_open_file_succeeded(FILE *curr_file, boolean is_fatal, const char *file_name) {
    boolean result=true;
    if(curr_file==NULL){
        result=false;
        fprintf(stderr,"Unable to open file: %s\n",file_name);
        if (is_fatal){
            exit(OPEN_FILE_EXIT_CODE);
        }
    }
    return result;
}