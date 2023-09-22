#include <stdio.h>
#include <cstdlib>
#include "onegin_functions.h"
#include "sorts_functions.h"
#include <string.h>


int main(int argc, char* argv[]){
    const int MAX_LEN_OF_FILE_NAME = 100;



    printf("Hello, it's str sorter\nWrite name of file which you want to sort\n");
    char name_file_source[MAX_LEN_OF_FILE_NAME] = {};
    scanf("%s", name_file_source);

    FILE* file_source = fopen(name_file_source, "r");
    if(!file_source){
        printf("Maybe, you write file name wrong\n");
    }
    else{
        char* buff = file_to_dynamic_str(file_source);
        int count_of_strs = count_of_strs_in_buff(buff);
        char** mass_of_onegin_strs = buff_to_dynamic_mass_of_strs(buff, (size_t)count_of_strs);

        quick_sort(sizeof(char*), mass_of_onegin_strs, mass_of_onegin_strs + count_of_strs - 1, comp_str_from_end);

        printf("Now write name of file to which strings go\n");
        char name_file_dest[MAX_LEN_OF_FILE_NAME] = {};
        while(getchar() != '\n'){}
        scanf("%s", name_file_dest);

        FILE* file_dest = fopen(name_file_dest, "w");

        write_mass_of_strs_to_file(file_dest, mass_of_onegin_strs, count_of_strs);

        free(mass_of_onegin_strs);
        free(buff);
        fclose(file_source);
        fclose(file_dest);

        printf("Ok, done\n");
    }
}
