#include <stdio.h>
#include <cstdlib>
#include "onegin_functions.h"
#include "sorts_functions.h"
#include <string.h>


int main(){
    FILE* file_source = fopen("onegin.txt", "r");
    char* buff = file_to_dynamic_str(file_source);
    int count_of_strs = count_of_strs_in_buff(buff);
    char** mass_of_onegin_strs = buff_to_dynamic_mass_of_strs(buff, (size_t)count_of_strs);

    quick_sort(sizeof(char*), mass_of_onegin_strs, mass_of_onegin_strs + count_of_strs - 1, comp_str_from_end);

    FILE* file_dest = fopen("out.txt", "w");

    write_mass_of_strs_to_file(file_dest, mass_of_onegin_strs, count_of_strs);

    free(mass_of_onegin_strs);
    free(buff);
    fclose(file_source);
    fclose(file_dest);

}
