#pragma once

enum TYPE_OF_SORT{
    BUBBLE_SORT = 0;
    CHOICE_SORT = 1;
    QUICK_SORT = 2;
}

enum COMPARATOR{
    INCREASING_ORDER = 0;
    INCREASING_ORDER_FROM_END = 1;
}



size_t my_strlen_with_n(const char* str);
bool comp_str_from_end(const void* x1, const void* x2);

char* file_to_dynamic_str(FILE* file);
int count_of_strs_in_buff(char* buff);
char** buff_to_dynamic_mass_of_strs(char* buff, size_t count_of_strs);
void write_str_before_n_to_file(FILE* file_dest, char* str);
void write_mass_of_strs_to_file(FILE* file_dest, char** mass_of_onegin_strs, int count_of_strs);
