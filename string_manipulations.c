/*
* Created by Avishav & Sapir on March 2, 2022
*/

#include "string_manipulations.h"

#define BUFFER_SIZE 256

/* public functions implementation */
char* trim_whitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str))
        str++;
    if (*str == 0)
        return str;
    end = str + strlen(str) - 1;
    while ((end > str) && (isspace((unsigned char)*end)))
        end--;
    end[1] = '\0';
    return str;
}

int split(char *src, char ***dest, const char *delimiter) {
    int i = 0;
    char *temp;
    temp = strtok(src,delimiter);
    while (temp != NULL) {
        *dest = (char **)realloc(*dest, (i+1)* sizeof(char *));
        (*dest)[i] = temp;
        temp = strtok(NULL,delimiter);
        i++;
    }
    return i;
}

char is_zero(char *str) {
    char result = 1;
    int i = 1;
    char point_flag = 0;
    if ((*str != '0') && (*str !='-') && (*str !='+') && (*str !='.')) {
        result = 0;
    }
    if (*str == '.') {
        point_flag = 1;
    }
    while ((result) && (i < strlen(str))) {
        if (str[i] == '.') {
            if (point_flag) {
                result = 0;
            }
            point_flag = 1;
        } else if (str[i]) {
            result = 0;
        }
        ++i;
    }
    return result;
}

int str_to_int(char *str,int *dest) {
    int result = 1;
    str = trim_whitespace(str);
    if (is_zero(str)) {
        *dest = 0;
    } else {
        char *end;
        *dest = strtol(str,&end,10);
        if (*end || !*dest) {
            result = 0;
        }
    }
    return result;
}

boolean is_alpha_numeric_word(char *word) {
    unsigned long len;
    boolean result = true;
    len = strlen(word);
    while (len) {
        --len;
        if (!isalnum(word[len])) {
            result = false;
        }
    }
    return result;
}

char* str_tok(char *src,const char *delim) {
    static char buffer[BUFFER_SIZE];
    if (src != NULL) {
        strcpy(buffer,src);
        src = buffer;
    }
    return strtok(src, delim);
}

unsigned long number_of_not_spaces_chars(char *string) {
    unsigned long result = 0, string_len;
    string_len = strlen(string);
    while (string_len > 0) {
        string_len--;
        if (!isspace(string[string_len])) {
            result++;
        }
    }
    return result;
}
/* end of public functions implementation */