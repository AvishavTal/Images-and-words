/*
* Created by Avishav & Sapir on March 2, 2022
*/

#include "string_manipulations.h"

#define BUFER_SIZE 256

/**
 * trim the whitespaces from the edges of the given string
 * @param str
 * @return
 */
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

/**
 * split the given string to several strings
 * @param src the string to split
 * @param dest 2D array to hold the output strings
 * @param delimiter
 * @return the number of strings
 */
int split(char *src, char ***dest, const char *delimiter) {
    int i;
    char *temp;
    i=0;
    temp=strtok(src,delimiter);
    while (temp!=NULL){
        *dest=(char **)realloc(*dest, (i+1)* sizeof(char *));
        (*dest)[i]=temp;
        temp=strtok(NULL,delimiter);
        i++;
    }
    return i;
}

/**
 * check if given string represent the number zero.
 * @param str
 * @return 0 iff str is not representation of 0.
 */
char is_zero(char *str) {
    char result=1;
    int i=1;
    char point_flag=0;
    if(*str != '0' && *str !='-' && *str !='+' && *str !='.'){
        result=0;
    }
    if (*str=='.'){
        point_flag=1;
    }
    while (result&&i< strlen(str)){
        if (str[i]=='.'){
            if (point_flag){
                result=0;
            }
            point_flag=1;
        } else if (str[i]){
            result=0;
        }
        ++i;
    }
    return result;
}


/**
 * convert string to int
 * @param str string to convert
 * @return 0 iff the string contains non numeric chars
 */
int str_to_int(char *str,int *dest){
    int result=1;
    str= trim_whitespace(str);
    if(is_zero(str)){
        *dest=0;
    } else{
        char *end;
        *dest= strtol(str,&end,10);
        if(*end || !*dest){
            result=0;
        }
    }
    return result;
}

boolean is_alpha_numeric_word(char *word){
    unsigned long len;
    boolean result=true;
    len= strlen(word);
    while (len){
        --len;
        if(!isalnum(word[len])){
            result=false;
        }
    }
    return result;

}

char *str_tok(char *src,const char *delim){
    static char buffer[BUFER_SIZE];
    if(src!=NULL){
        strcpy(buffer,src);
        src=buffer;
    }
    return strtok(src, delim);
}

/**
 * count the non spaces chars
 * @param string
 * @return the number of non spaces chars in string
 */
unsigned long number_of_not_spaces_chars(char *string){
    unsigned long result=0,string_len;
    string_len= strlen(string);
    while (string_len>0){
        string_len--;
        if(!isspace(string[string_len])){
            result++;
        }
    }
    return result;
}