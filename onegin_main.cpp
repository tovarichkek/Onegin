#include <stdio.h>
#include <cstdlib>
#include "onegin_functions.h"
#include "sorts_functions.h"



int main(){

/*
    FILE* file = fopen("ex.txt", "r");
    char* s = file_to_str(file);
    int count_of_strs = 1;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '\n'){
            count_of_strs++;
        }
    }
    char** mass_of_onegin_strs = (char**)calloc(count_of_strs, sizeof(char*));
    mass_of_onegin_strs[0] = s;
    int index = 1;
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i - 1] == '\n'){
            mass_of_onegin_strs[index] = s + i;
            index++;
        }
    }

    bubble_sort(sizeof(char*), mass_of_onegin_strs, mass_of_onegin_strs + count_of_strs-1, comp_str);
    for(int i = 0; i < count_of_strs-1; i++){
        puts(mass_of_onegin_strs[i]);
    }
    free(mass_of_onegin_strs);
    free(s);
*/
    const char** mass_of_p_str = (const char**)calloc(5, sizeof(char*));
    mass_of_p_str[0] = "csdv";
    mass_of_p_str[1] = "dcd";
    mass_of_p_str[2] = "evfs";
    mass_of_p_str[3] = "bvfs";
    mass_of_p_str[4] = "avfs";
    bubble_sort(sizeof(char*), mass_of_p_str, mass_of_p_str + 5, comp_str);
    for(int i = 0; i < 5; i++){
        printf("%s ", mass_of_p_str[i]);
    }
    printf("\n");
    free(mass_of_p_str);

    //printf("%d\n", comp_str("csdv", "bvfs"));
}
