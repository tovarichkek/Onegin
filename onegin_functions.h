#pragma once


char* file_to_dynamic_str(FILE* file);
int count_of_strs_in_buff(char* buff);
char** buff_to_dynamic_mass_of_strs(char* buff, size_t count_of_strs);
void write_str_before_n_to_file(FILE* file_dest, char* str);
void write_mass_of_strs_to_file(FILE* file_dest, char** mass_of_onegin_strs, int count_of_strs);
