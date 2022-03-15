/*
* Created by Avishav & Sapir on March 2,2022
*/

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "string_manipulations.h"
#include "system_errors.h"
#include "parser.h"

char *trim_whitespace(char *str){
    char *end;
    while(isspace((unsigned char)*str))
        str++;
    if(*str == 0)
        return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end))
        end--;
    end[1] = '\0';
    return str;
}

int split(char *src, char **dest, const char *delimiter){
    int i;
    char *temp;
    i=0;
    temp=strtok(src,delimiter);
    while (temp!=NULL){
        dest=(char **)realloc(dest, (i+1)* sizeof(char *));
        dest[i]=temp;
        temp=strtok(NULL,delimiter);
        i++;
    }
    return i;
}

boolean is_zero(char *str){
    boolean result=true;
    int i=1;
    char point_flag=false;
    if(*str != '0' && *str !='-' && *str !='+' && *str !='.'){
        result=false;
    }
    if (*str=='.'){
        point_flag=true;
    }
    while (result&&i< strlen(str)){
        if (str[i]=='.'){
            if (point_flag){
                result=false;
            }
            point_flag=true;
        }else if (str[i]){
            result=false;
        }
        ++i;
    }
    return result;
}

int str_to_double(char *str, double *dest){
    int result=1;
    str=trim_whitespace(str);
    if(is_zero(str)){
        *dest= 0;
    }else{
        *dest= atof(str);
        if (!(*dest)){
            result=0;
        }
    }
    return result;
}

int str_to_int(char *str,int *dest){
    int result=1;
    str=trim_whitespace(str);
    if(is_zero(str)){
        *dest=0;
    }else{
        char *end;
        *dest= strtol(str,&end,10);
        if(*end || !*dest){
            result=0;
        }
    }
    return result;
}

char* get_first_word_in_line(char *str){
    char *first_word;
    int str_index;

    if(is_empty(str))
        return NULL;

    str_index=0;
    first_word=(char*)calloc(1,strlen(str)+1);
    if(is_allocation_succeeded(first_word)) {
        while (isspace(str[str_index])) {
            first_word[str_index] = str[str_index];
            str_index++;
        }
        while (!(isspace(str[str_index]))) {
            first_word[str_index] = str[str_index];
            str_index++;
        }
    }
    return first_word;
}

boolean is_alpha_numeric_word(char *word){
    unsigned long len;
    boolean result;
    result=true;
    len= strlen(word);
    while (len){
        --len;
        if(!isalnum(word[len])){
            result=false;
        }
    }
    return result;
}