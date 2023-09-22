#include <stdio.h>
#include <string.h>
#include "my_asserts.h"
#include "onegin_functions.h"

size_t my_strlen_with_n(const char* str){
    my_assert(str != NULL, return 0);

    size_t index = 0;
    while(str[index] != '\0' && str[index] != '\n'){
        index++;
    }
    return index;
}

bool comp_str_from_end(const void* x1, const void* x2){
    my_assert(x1 != NULL, printf("pointer to first compared element is NULL\n"); return false);
    my_assert(x2 != NULL, printf("pointer to second compared element is NULL\n"); return false);

    int index_first = (int)my_strlen_with_n(*((const char*const*)x1));
    int index_second = (int)my_strlen_with_n(*((const char*const*)x2));

    while((index_first >= 0) && (index_second >= 0)){
        if(*((*((const char*const*)x1)) + index_first) > *((*((const char*const*)x2)) + index_second)){
            return true;
        }
        if(*((*((const char*const*)x1)) + index_first) < *((*((const char*const*)x2)) + index_second)){
            return false;
        }
        index_first--;
        index_second--;
    }
    return false;
}

char* file_to_dynamic_str(FILE* file){
    my_assert(file != NULL, return NULL);
    fseek(file, 0, SEEK_END);

    long int size_of_file = ftell(file);
    char* str = (char*)calloc((size_t)size_of_file + 1, sizeof(char));  //+1 for '/0'
    fseek(file, 0, SEEK_SET);

    fread(str, (size_t)size_of_file, sizeof(char), file);

    return str;
}

int count_of_strs_in_buff(char* buff){
    my_assert(buff != NULL, return -1);
    int count_of_strs = 0;
    for(int i = 0; buff[i] != '\0'; i++){
        if(buff[i] == '\n'){
            count_of_strs++;
        }
    }
    return count_of_strs;
}

char** buff_to_dynamic_mass_of_strs(char* buff, size_t count_of_strs){
    my_assert(buff != NULL, return NULL);

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
    my_assert(file_dest != NULL, return);
    my_assert(str != NULL, return);

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
    my_assert(file_dest != NULL, return);
    my_assert(mass_of_onegin_strs != NULL, return);
    my_assert(count_of_strs >= 0, return);

    for(int i = 0; i < count_of_strs; i++){
        write_str_before_n_to_file(file_dest, mass_of_onegin_strs[i]);
    }
}

