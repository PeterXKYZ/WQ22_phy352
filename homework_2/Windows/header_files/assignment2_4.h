// Peter Zhou
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int date;
    float temperature;
} DateAndTime;

DateAndTime* scan_both_to_array(FILE*, size_t, const char*, bool);

void swap(DateAndTime*, DateAndTime*);

void qsort_TD2(DateAndTime*, DateAndTime*);

