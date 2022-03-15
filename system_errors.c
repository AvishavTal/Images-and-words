/*
* Created by Avishav & Sapir on March 15,2022
*/

#include <stdlib.h>
#include "boolean.h"
#include "system_errors.h"

#define EXIT_CODE -1

boolean is_allocation_succeeded(void* pointer){
    if(pointer == NULL){
        fprintf( stderr, "Unable to allocate memory for new node\n");
        exit(EXIT_CODE);
    }
    return true;
}
