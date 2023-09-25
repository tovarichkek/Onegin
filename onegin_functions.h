#pragma once

size_t my_strlen_with_n(const char* str);
bool comp_str_from_end(const void* x1, const void* x2);

char* file_to_dynamic_str(FILE* file);
int count_of_strs_in_buff(char* buff);
char** buff_to_dynamic_mass_of_strs(char* buff, size_t count_of_strs);
void write_str_before_n_to_file(FILE* file_dest, char* str);
void write_mass_of_strs_to_file(FILE* file_dest, char** mass_of_onegin_strs, int count_of_strs);
