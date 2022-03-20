//
// Created by avishav on 2.3.2022.
//
#include <stdio.h>
#include <string.h>
#include "system_errors.h"
#include "string_manipulations.h"
#include "macro_table.h"
#include "file.h"
#include "parser.h"

#define LINE_SIZE 81


void write_line(FILE *dest, char *line);

void pre_assembler(file source) {
    FILE *src,*dest;
    int macro_definition=0;
    char line[LINE_SIZE],temp_line[LINE_SIZE],*first_word_in_line;
    macro temp_macro;
    macro_table table= get_macro_table(source);
    src= fopen(get_name_as(source),"r");
    if (!is_open_file_succeeded(src,false, get_name_as(source))) {
        mark_pre_assembler_failed(source);
    } else{
        dest= fopen(get_name_am(source),"w");
        if (is_open_file_succeeded(dest,true, get_name_am(source))){
            while ((fgets(line,LINE_SIZE,src)!=NULL)){
                strcpy(temp_line,line);
                first_word_in_line= strtok(temp_line," \t");
                trim_whitespace(first_word_in_line);
                if(!macro_definition){
                    if((temp_macro= get_macro_by_name(table, first_word_in_line)) != NULL){/*macro call*/
                        macro_call(dest,temp_macro);
                    } else if(start_of_macro_definition(first_word_in_line)){
                        char *name;
                        temp_macro=init_macro();
                        macro_definition=1;
                        name= strtok(NULL," \t");
                        set_macro_name(temp_macro, name);
                    } else{
                        write_line(dest,line);
                    }
                } else{
                    if(end_of_macro_definition(first_word_in_line)){
                        push_macro(table, temp_macro);
                        macro_definition=0;
                    } else{
                        append_line(temp_macro,line);
                    }
                }
            }
            fclose(dest);
        }
        fclose(src);
    }
}

void write_line(FILE *dest, char *line) {
    fprintf(dest,"%s",line);
}
