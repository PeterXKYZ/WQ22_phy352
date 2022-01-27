#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int order;
    double* weights;
    double* nodes;
    double** matrix;
} ButcherTableau;

/*
typedef struct{
    int num_var;
    double A;
    double B;
} MultiComponent;
*/

double dot_product(double* x, double* y, size_t length) {
    double total = 0;
    for (int i = 0; i < length; ++i) {
        total += x[i] * y[i];
    }
    return total;
}

double* constant_add(const double* a, double s, size_t length) {
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

double* constant_multiply(const double* a, double s, size_t length) {
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

void dot_add(double* a, const double* b, size_t length) {
    for (int i = 0; i < length; ++i) {
        a[i] += b[i];
    }
}



// k = array[order][num_var]
/*
void ode_step(double** x, double* t, double** k,
                double* dxdt_param, double dt, int steps,
                ButcherTableau method, size_t num_var) 
{
    for (int j = 0; j < num_var; ++j) {
        *(*(x+1)+j) = *(*x+j) + dt * dot_product(k[j], method.weights, method.order);
    }
    *(t + 1) = *t + dt;
}
*/

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

#define MAX_TIME 50
#define NUM_VAR 1

double dxdt(double* x_arr, double t, double* param) {
    double deriv = -param[0] * x_arr[0] / param[1];
    return deriv;
}

int main(void) {
    int order = 4;
    double weights[] = {(double)1/6, (double)1/3, (double)1/3, (double)1/6};
    double nodes[] = {0, 0.5, 0.5, 1};
    double** matrix = malloc(4 * sizeof(double*));
    
    double matrix_val[4][4] = {{0, 0, 0, 0}, 
                            {0.5, 0, 0, 0}, 
                            {0, 0.5, 0, 0}, 
                            {0, 0, 1, 0}};

    for (int i = 0; i < order; ++i) {
        matrix[i] = malloc(4 * sizeof(double));
        for (int j = 0; j < order; ++j) {
            matrix[i][j] = matrix_val[i][j];
        } 
    }

    //printf("%lf\n", matrix_val[1][0]);
    //printf("%lf\n", matrix[1][0]);
    printf("%lf\n", weights[0]);
    
    double (*func[NUM_VAR]) (double*, double, double*);
    func[0] = dxdt;
    
    double t[MAX_TIME];
    double dt = 0.1;
    double fparam[] = {1, 3}; // dxdt = -Nx / tau
    double** x = malloc(MAX_TIME * sizeof(double *));
    for (int i = 0; i < MAX_TIME; ++i) {
        x[i] = malloc(NUM_VAR * sizeof(double));
    }

    x[0][0] = 100;
    ButcherTableau method = {order, weights, nodes, matrix};

    ode_solver(x, t, func, fparam, dt, MAX_TIME, method, NUM_VAR);

    for (int i = 0; i < MAX_TIME; ++i) {
        printf("t: %lf \t x: %lf\n", t[i], x[i][0]);
    }
    


    
    for (int i = 0; i < order; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    for (int i = 0; i < NUM_VAR; ++i) {
            free(x[i]);
    }
    free(x);

    return 0;
}
