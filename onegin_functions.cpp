#include <stdio.h>
#include "my_asserts.h"
#include "onegin_functions.h"


char* file_to_dynamic_str(FILE* file){
    fseek(file, 0, SEEK_END);

    long int size_of_file = ftell(file);
    char* str = (char*)calloc((size_t)size_of_file + 1, sizeof(char));  //+1 for '/0'
    fseek(file, 0, SEEK_SET);

    fread(str, (size_t)size_of_file, sizeof(char), file);

    return str;
}

int count_of_strs_in_buff(char* buff){
    int count_of_strs = 0;
    for(int i = 0; buff[i] != '\0'; i++){
        if(buff[i] == '\n'){
            count_of_strs++;
        }
    }
    return count_of_strs;
}

char** buff_to_dynamic_mass_of_strs(char* buff, size_t count_of_strs){
    char** mass_of_onegin_strs = (char**)calloc(count_of_strs+1, sizeof(char*));
    mass_of_onegin_strs[0] = buff;
    int index = 1;
    for(int i = 0; buff[i] != '\0'; i++){
        if(buff[i] == '\n'){
            mass_of_onegin_strs[index] = buff + i + 1;
            index++;
        }

    }
    return mass_of_onegin_strs;
}

void write_str_before_n_to_file(FILE* file_dest, char* str){
    int index = 0;
    while((str[index] != '\n')&&(str[index] != '\0')){
        putc(str[index], file_dest);
        index++;
    }
    if(str[index] == '\n'){
        putc(str[index], file_dest);
    }
}

void write_mass_of_strs_to_file(FILE* file_dest, char** mass_of_onegin_strs, int count_of_strs){
    for(int i = 0; i < count_of_strs; i++){
        write_str_before_n_to_file(file_dest, mass_of_onegin_strs[i]);
    }
}

