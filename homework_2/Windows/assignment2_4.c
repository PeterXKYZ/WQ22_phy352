// Peter Zhou
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "assignment2_1.h"
#include "assignment2_4.h"

int main(void) {
    FILE* data = fopen("chicago_temps_2012.csv", "r");
    FILE* sorted_data = fopen("chicago_tempSorted_2012_2.csv", "w");

    size_t length = find_file_length(data, true);

    DateAndTime* td_array = scan_both_to_array(data, length, "%i-%i-%i, %*f, %f, %*f", true);

    qsort_TD2(td_array, td_array+length-1);

    for (int i = 0; i < length; ++i) {
        int day = td_array[i].date / 1000000;
        int month = (td_array[i].date / 10000) % 100;
        int year = td_array[i].date % 10000;

        fprintf(sorted_data, "%i-%i-%i, %f\n", year, month, day, td_array[i].temperature);
    }

    fclose(data);
    fclose(sorted_data);
    
    free(td_array);
    return 0;
}

DateAndTime* scan_both_to_array(FILE* data, size_t length, const char* str_format, bool ignore_first_line) {
    DateAndTime* struct_array = calloc(length, sizeof(DateAndTime));
    if (struct_array == NULL) {
        exit(1); 
    }

    DateAndTime* dst = struct_array;

    if (ignore_first_line) {
        fscanf(data, "%*s");
    }

    int day;
    int month;
    int year;
    float temp;

    while (fscanf(data, str_format, &year, &month, &day, &temp) != EOF) {
        dst->temperature = temp;
        dst->date = (1000000*day) + (10000*month) + year;
        ++dst;
    }

    rewind(data);
    return struct_array;
}

void swap(DateAndTime* ptr1, DateAndTime* ptr2) {
    DateAndTime temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void qsort_TD2(DateAndTime* left, DateAndTime* right) {
    DateAndTime* ptr = NULL;
    DateAndTime* last = NULL; 
    DateAndTime* middle = NULL; 

    if (left >= right) {
        return;
    }

    middle = left + (right - left) / 2;
    swap(left, middle);

    last = left;
    ptr = left + 1;
    while (ptr <= right) {
        if (ptr->temperature < left->temperature) {
            swap(++last, ptr);
        }
        ++ptr;
    }

    swap(left, last);
    qsort_TD2(left, last-1);
    qsort_TD2(last+1, right);
}