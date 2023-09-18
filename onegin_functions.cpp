#include <stdio.h>
#include "my_asserts.h"
#include "onegin_functions.h"


char* file_to_str(FILE* file){
    fseek(file, 0, SEEK_END);

    long int size_of_file = ftell(file);
    char* str = (char*)calloc((size_t)size_of_file + 1, sizeof(char));  //+1 for '/0'
    fseek(file, 0, SEEK_SET);

    fread(str, (size_t)size_of_file, sizeof(char), file);

    return str;
}
