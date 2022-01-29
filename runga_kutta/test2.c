#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int order;
    double* weights;
    double* nodes;
    double** matrix;
} ButcherTableau;

static double* constant_multiply(const double* a, double s, int length) {
    double* dst = calloc(length, sizeof(double));
    if (!dst) {
        fprintf(stderr, "Can't allocate");
        exit(1);
    }

    for (int i = 0; i < length; ++i) {
        dst[i] = a[i] * s;
    }

    return dst;
}

static void dot_add(double* a, const double* b, int length) {
    for (int i = 0; i < length; ++i) {
        a[i] += b[i];
    }
}

void ode_solver(double** x, double* t, 
                double (**dxdt) (double* x, double, double*),
                double* dxdt_param, double dt, int steps, 
                ButcherTableau method, int num_var) {
    
    double k[method.order][num_var];

    for (int i = 0; i < steps-1; ++i) {

        for (int n = 0; n < num_var; ++n) {
            x[i+1][n] = x[i][n];
        }
        
        for (int j = 0; j < method.order; ++j) {
            double want[num_var];
            for (int m = 0; m < num_var; ++m) {
                want[m] = x[i][m];
            }

            for (int l = 0; l < j; ++l) {
                double* temp1 = constant_multiply(k[l], dt * method.matrix[j][l], num_var); 
                dot_add(want, temp1, num_var);
                free(temp1);
            }

            for (int n = 0; n < num_var; ++n) {
                k[j][n] = dxdt[n](want, t[i] + method.nodes[j]*dt, dxdt_param);
            }
            
            double* temp2 = constant_multiply(k[j], dt * method.weights[j], num_var);
            dot_add(x[i+1], temp2, num_var);
            free(temp2);
        }
        
        t[i+1] = t[i] + dt;
    }
}

ButcherTableau constructor_helper(int order, double* weights_ptr, double* nodes_ptr, double* matrix_ptr) {
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

#define MAX_TIME 51
#define NUM_VAR 2

double dx1dt(double* x, double t, double* param) {
    double deriv = x[1];
    return deriv;
}

double dx2dt(double* x, double t, double* param) {
    double deriv = -param[0] * x[0] / param[1];
    return deriv;
}


int main(void) {
    double (*func[NUM_VAR]) (double*, double, double*);
    func[0] = dx1dt;
    func[1] = dx2dt;
    
    double dt = 0.1;
    // fparam[0] = g, fparam[1] = 1
    double fparam[] = {9.81, 1} ;
    
    // x[0] = theta, x[1] = omega
    double x_init[] = {.3, 0};
    
    double* t = t_constructor(MAX_TIME, 0);
    double** x = x_constructor(NUM_VAR, MAX_TIME, x_init);
    
    ButcherTableau method = rk_method_constructor("classic_rk");

    ode_solver(x, t, func, fparam, dt, MAX_TIME, method, NUM_VAR);

    for (int i = 0; i < MAX_TIME; ++i) {
        printf("t: %lf \t x1: %lf \t x2: %lf\n", t[i], x[i][0], x[i][1]);
    }

    tableau_destroyer(method);

    t_destroyer(t);
    x_destroyer(x, MAX_TIME);

    return 0;
}
