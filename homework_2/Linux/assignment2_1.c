// Peter Zhou
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "assignment2_1.h"


size_t find_file_length(FILE* data, bool ignore_first_line) {
    size_t array_length = 0;

    if (ignore_first_line) {
        fscanf(data, "%*s");
    }

    for ( ; fscanf(data, "%*s") != EOF; ++array_length); // %*s = scan for a string but don't store it anywhere

    rewind(data);
    return array_length;
}

float* scan_temp_to_array(FILE* data, size_t length, const char* str_format, bool ignore_first_line) {

    float* avg_temp = calloc(length, sizeof(float)); // allocates heap memory; remember to free later
    if (!avg_temp) {
        return NULL;
    }

    float* dst = avg_temp;

    if (ignore_first_line) {
        fscanf(data, "%*s");
    }

    for ( ; fscanf(data, str_format, dst) != EOF; ++dst);

    rewind(data); // go to the beginning of the file so we can use fscanf again 
    return avg_temp;
}

int* scan_date_to_array(FILE* data, size_t length, const char* str_format, bool ignore_first_line) {

    int* dates = calloc(length, sizeof(int));
    if (!dates) {
        return NULL;
    }

    int* dst = dates;

    if (ignore_first_line) {
        fscanf(data, "%*s");
    }

    int day;
    int month;
    int year;

    while (fscanf(data, str_format, &year, &month, &day) != EOF) {
        *dst = (1000000*day) + (10000*month) + year;
        ++dst;
    }

    rewind(data);    
    return dates;
}



