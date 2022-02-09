#include <constructors.h>
#include <stdlib.h>

double** arr_2D_constructor(int arr_len, int sub_arr_len) {
    double** arr_2D = malloc(arr_len * sizeof(double *));
    for (int i = 0; i < arr_len; ++i) {
        arr_2D[i] = malloc(sub_arr_len * sizeof(double));
    }

    return arr_2D;
}

void arr_2D_destroyer(double** arr_2D, int arr_len) {
    for (int i = 0; i < arr_len; ++i) {
        free(arr_2D[i]);
    }
    free(arr_2D);
}