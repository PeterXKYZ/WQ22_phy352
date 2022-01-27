#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int order;
    double* weights;
    double* nodes;
    double** matrix;
} ButcherTableau;

static double dot_product(double* x, double* y, size_t length) {
    double total = 0;
    for (int i = 0; i < length; ++i) {
        total += x[i] * y[i];
    }
    return total;
}

static double* constant_add(const double* a, double s, size_t length) {
    double* dst = calloc(length, sizeof(double));
    if (!dst) {
        fprintf(stderr, "Can't allocate");
        exit(1);
    }

    for (int i = 0; i < length; ++i) {
        dst[i] = a[i] + s;
    }

    return dst;
}

static double* constant_multiply(const double* a, double s, size_t length) {
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

static void dot_add(double* a, const double* b, size_t length) {
    for (int i = 0; i < length; ++i) {
        a[i] += b[i];
    }
}

void ode_solver(double** x, double* t, 
                double (**dxdt) (double* x, double, double*),
                double* dxdt_param, double dt, int steps, 
                ButcherTableau method, int num_var) {
    
    double k[method.order][num_var];
    for (int i = 0; i < method.order; ++i) {
        for (int j = 0; j < num_var; ++j) {
            k[i][j] = 0;
        }
    }


    for (int i = 0; i < steps-1; ++i) {
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
                // printf("%lf\n", k[j][n]);
            }
        }
        // ode_step(x+i, t+i, k, dxdt_param, dt, steps, method, num_var);

        for (int j = 0; j < num_var; ++j) {
            x[i+1][j] = x[i][j] + dt * dot_product(k[j], method.weights, method.order);
            }

        t[i+1] = t[i] + dt;
    }
}

ButcherTableau get_rk_tableau(void) {
    int order = 4;

    double weights_val[] = {(double)1/6, (double)1/3, (double)1/3, (double)1/6};
    double nodes_val[] = {0, 0.5, 0.5, 1};
    double matrix_val[4][4] = {{0, 0, 0, 0}, 
                            {0.5, 0, 0, 0}, 
                            {0, 0.5, 0, 0}, 
                            {0, 0, 1, 0}};

    double** matrix = malloc(4 * sizeof(double*));
    if (!matrix) {
        exit(1);
    }
    double* weights = malloc(4 * sizeof(double));
    double* nodes = malloc(4 * sizeof(double));

    for (int i = 0; i < order; ++i) {
        matrix[i] = malloc(4 * sizeof(double));
        if (!matrix[i]) {
            exit(1);
        }
        nodes[i] = nodes_val[i];
        weights[i] = weights_val[i];

        for (int j = 0; j < order; ++j) {
            matrix[i][j] = matrix_val[i][j];
        } 
    }

    ButcherTableau method = {order, weights, nodes, matrix};
    return method;
}

void destroy_rk_tableau(ButcherTableau method) {
    for (int i = 0; i < method.order; ++i) {
        free(method.matrix[i]);
    }
    free(method.nodes);
    free(method.weights);
    free(method.matrix);
}

double** x_constructor(int num_var, int max_time) {
    double** x = malloc(max_time * sizeof(double *));
    for (int i = 0; i < max_time; ++i) {
        x[i] = malloc(num_var * sizeof(double));
    }
    return x;
}

void x_destroyer(double** x, int max_time) {
    for (int i = 0; i < max_time; ++i) {
        free(x[i]);
    }
    free(x);
}

#define MAX_TIME 50
#define NUM_VAR 1

double dxdt(double* x_arr, double t, double* param) {
    double deriv = -param[0] * x_arr[0] / param[1];
    return deriv;
}

int main(void) {
    double (*func[NUM_VAR]) (double*, double, double*);
    func[0] = dxdt;
    
    double t[MAX_TIME];
    double dt = 0.1;
    double fparam[] = {1, 3}; // dxdt = -Nx / tau
    
    double** x = x_constructor(NUM_VAR, MAX_TIME);
    x[0][0] = 100;
    
    ButcherTableau method = get_rk_tableau();

    ode_solver(x, t, func, fparam, dt, MAX_TIME, method, NUM_VAR);

    for (int i = 0; i < MAX_TIME; ++i) {
        printf("t: %lf \t x: %lf\n", t[i], x[i][0]);
    }
    
    destroy_rk_tableau(method);

    // x_destroyer(x, MAX_TIME);


    for (int i = 0; i < MAX_TIME; ++i) {
        free(x[i]);
    }
    free(x); 
    return 0;
}
