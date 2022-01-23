// Peter Zhou
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "assignment2_1.h"
#include "assignment2_2.h"

int main(void) {
    FILE* data = fopen("chicago_temps_2012.csv", "r");
    FILE* sorted_data = fopen("chicago_tempSorted_2012.csv", "w");

    size_t length = find_file_length(data, true);

    float* temp_array = scan_temp_to_array(data, length, "%*i-%*i-%*i, %*f, %f, %*f", true);
    int* date_array = scan_date_to_array(data, length, "%i-%i-%i, %*s", true);
    
    qsortTD(temp_array, temp_array+length-1, date_array, date_array+length-1);

    for (int i = 0; i < length; ++i) {
        int day = date_array[i] / 1000000;
        int month = (date_array[i] / 10000) % 100;
        int year = date_array[i] % 10000;

        fprintf(sorted_data, "%i-%i-%i, %f\n", year, month, day, temp_array[i]);
    }

    fclose(data);
    fclose(sorted_data);

    free(date_array);
    free(temp_array);
    return 0;
}