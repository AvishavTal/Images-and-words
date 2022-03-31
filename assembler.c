/*
* Created by Avishav & Sapir on March 9, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "pre_assembler.h"
#include "first_scan.h"
#include "second_scan.h"
#include "system_errors.h"

#define LINE_LENGTH 81

file *init_files(file *files, int n_files, char **names);
void run_assembler(file *files, int n_files);

int main(int argc, char **argv){
    file *files=NULL;
    files= init_files(files,argc-1,argv+1);
    run_assembler(files,argc-1);
    free(files);
    return 0;
}

/*
 * do the actual work
 */
void run_assembler(file *files, int n_files) {
    int i=0;
    for (; i < n_files; ++i) {
        if (files[i]){
            pre_assembler(files[i]);
            if (has_passed_pre_assembler(files[i])){
                first_scan(files[i]);
                if (has_passed_first_scan(files[i])){
                    second_scan(files[i]);
                    if (has_passed_second_scan(files[i])){
                        make_ent_file(files[i]);
                        make_ext_file(files[i]);
                    }
                }
            }
        }
        tear_down(files[i]);
    }
}

/*
 * init the file objects of the program
 */
file *init_files(file *files, int n_files, char **names) {
    int i=0;
    files=(file *) malloc(sizeof(file)*n_files);
    if(is_allocation_succeeded(files)) {
        for (; i < n_files; ++i) {
            files[i] = init_file(names[i]);
        }
    }
    return files;
}