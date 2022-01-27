// Peter Zhou
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// find the number of entries in a .csv file
// FILE*: file pointer to a .csv file
// bool: set to TRUE to skip counting the first line
size_t find_file_length(FILE*, bool);

// scan temperature data from a .csv file to an array; uses calloc
// FILE*: pointer to .csv file
// size_t: length of the file
// const char*: the string format to use in fscanf
// bool: whether to skip the first line
// return: an array of floats
float* scan_temp_to_array(FILE*, size_t, const char*, bool);

// basically the same as above
int* scan_date_to_array(FILE*, size_t, const char*, bool);