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
    double* weights_ptr;
    double* nodes_ptr;
    double* matrix_ptr;

    if (strcmp(name, "euler") == 0) {
        order = 1;

        double weights_val[1] = {1};
        weights_ptr = weights_val;

        double nodes_val[1] = {0};
        nodes_ptr = nodes_val;

        double matrix_val[1] = {0};
        matrix_ptr = matrix_val;
    }
    else if (strcmp(name, "mid_point") == 0) {
        order = 2;

        double weights_val[2] = {0, 1};
        weights_ptr = weights_val;

        double nodes_val[2] = {0, 0.5};
        nodes_ptr = nodes_val;

        double matrix_val[4] = {0, 0, 
                               0.5, 0};
        matrix_ptr = matrix_val;
    }
    else if (strcmp(name, "classic_rk") == 0) {
        order = 4;

        double weights_val[4] = {(double)1/6, (double)1/3, (double)1/3, (double)1/6};
        weights_ptr = weights_val;

        double nodes_val[4] = {0, 0.5, 0.5, 1};
        nodes_ptr = nodes_val;

        double matrix_val[16] = {0, 0, 0, 0,
                                 0.5, 0, 0, 0,
                                 0, 0.5, 0, 0,
                                 0, 0, 1, 0};
        matrix_ptr = matrix_val;
    }
    else {
        fprintf(stderr, "Not a valid method!");
        exit(1);
    }
    
    return constructor_helper(order, weights_ptr, nodes_ptr, matrix_ptr); 
}

void tableau_destroyer(ButcherTableau method) {
    for (int i = 0; i < method.order; ++i) {
        free(method.matrix[i]);
    }
    free(method.nodes);
    free(method.weights);
    free(method.matrix);
}

double* t_constructor(int max_time, double init) {
    double* t = malloc(max_time * sizeof(double));
    t[0] = init;
    return t;
}

void t_destroyer(double* t) {
    free(t);
}

double** x_constructor(int num_var, int max_time, double* init) {
    double** x = malloc(max_time * sizeof(double *));
    for (int i = 0; i < max_time; ++i) {
        x[i] = malloc(num_var * sizeof(double));
    }

    for (int j = 0; j < num_var; ++j) {
        x[0][j] = init[j];        
    }

    return x;
}

void x_destroyer(double** x, int max_time) {
    for (int i = 0; i < max_time; ++i) {
        free(x[i]);
    }
    free(x);
}
