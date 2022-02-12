#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <constructors.h>

static ButcherTableau constructor_helper(int order, double* weights_ptr, double* nodes_ptr, double* matrix_ptr) {
    double** matrix = malloc(order * sizeof(double*));
    double* weights = malloc(order * sizeof(double));
    double* nodes = malloc(order * sizeof(double));

    if (!matrix || !weights || !nodes) {
        fprintf(stderr, "Out of Memory!");
        exit(1);
    }

    int k = 0;
    for (int i = 0; i < order; ++i) {
        matrix[i] = malloc(order * sizeof(double));
        if (!matrix[i]) {
            fprintf(stderr, "Out of Memory!");
            exit(1);
        }
        nodes[i] = nodes_ptr[i];
        weights[i] = weights_ptr[i];

        for (int j = 0; j < order; ++j) {
            matrix[i][j] = matrix_ptr[k];
            ++k;
        } 
    }

    ButcherTableau method = {order, weights, nodes, matrix};
    return method;
}

ButcherTableau rk_method_constructor(char* name) {
    int order;
    // double* weights_ptr;
    // double* nodes_ptr;
    // double* matrix_ptr;

    if (strcmp(name, "euler") == 0) {
        order = 1;

        double weights_val[1] = {1};
        // weights_ptr = weights_val;

        double nodes_val[1] = {0};
        // nodes_ptr = nodes_val;

        double matrix_val[1] = {0};
        // matrix_ptr = matrix_val;
        return constructor_helper(order, weights_val, nodes_val, matrix_val); 
    }
    else if (strcmp(name, "mid_point") == 0) {
        order = 2;

        double weights_val[2] = {0, 1};
        // weights_ptr = weights_val;

        double nodes_val[2] = {0, 0.5};
        // nodes_ptr = nodes_val;

        double matrix_val[4] = {0, 0, 
                               0.5, 0};
        // matrix_ptr = matrix_val;
        return constructor_helper(order, weights_val, nodes_val, matrix_val);
    }
    else if (strcmp(name, "classic_rk") == 0) {
        order = 4;

        double weights_val[4] = {(double)1/6, (double)1/3, (double)1/3, (double)1/6};
        // weights_ptr = weights_val;

        double nodes_val[4] = {0, 0.5, 0.5, 1};
        // nodes_ptr = nodes_val;

        double matrix_val[16] = {0, 0, 0, 0,
                                 0.5, 0, 0, 0,
                                 0, 0.5, 0, 0,
                                 0, 0, 1, 0};
        // matrix_ptr = matrix_val;
        return constructor_helper(order, weights_val, nodes_val, matrix_val);
    }
    else {
        fprintf(stderr, "Not a valid method!");
        exit(1);
    }
}

void tableau_destroyer(ButcherTableau method) {
    for (int i = 0; i < method.order; ++i) {
        free(method.matrix[i]);
    }
    free(method.nodes);
    free(method.weights);
    free(method.matrix);
}

double* arr_1D_constructor(int arr_len) {
    double* arr_1D = malloc(arr_len * sizeof(double));
    if (!arr_1D) {
        fprintf(stderr, "Ran out of memory");
        exit(1);
    }

    return arr_1D;
}

void arr_1D_destroyer(double* arr_1D) {
    free(arr_1D);
}

double** arr_2D_constructor(int arr_len, int sub_arr_len) {
    double** arr_2D = malloc(arr_len * sizeof(double *));
    if (!arr_2D) {
        fprintf(stderr, "Ran out of memory");
        exit(1);
    }

    for (int i = 0; i < arr_len; ++i) {
        arr_2D[i] = malloc(sub_arr_len * sizeof(double));
        if (!arr_2D[i]) {
            fprintf(stderr, "Ran out of memory");
            exit(1);
        }
    }

    return arr_2D;
}

void arr_2D_destroyer(double** arr_2D, int arr_len) {
    for (int i = 0; i < arr_len; ++i) {
        free(arr_2D[i]);
    }
    free(arr_2D);
}
