#include <stdio.h>
#include <stdlib.h>

#include <constructors.h>
#include <rk_gen.h>

static void constant_multiply(double* dst, const double* a, double s, int length) {
    for (int i = 0; i < length; ++i) {
        dst[i] = a[i] * s;
    }
}

/*
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
}*/

static void dot_add(double* a, const double* b, int length) {
    for (int i = 0; i < length; ++i) {
        a[i] += b[i];
    }
}

void ode_solver(double** x_2D, double* t, 
                double (**dxdt) (double* x_1D, double t, double* param),
                double* dxdt_param, double dt, int steps, 
                ButcherTableau method, int num_var) {
    
    double k[method.order][num_var];
    double want[num_var];
    double storage[num_var];

    for (int i = 0; i < steps-1; ++i) {

        for (int n = 0; n < num_var; ++n) {
            x_2D[i+1][n] = x_2D[i][n];
        }
        
        for (int j = 0; j < method.order; ++j) {
            for (int m = 0; m < num_var; ++m) {
                want[m] = x_2D[i][m];
            }

            for (int l = 0; l < j; ++l) {
                constant_multiply(storage, k[l], dt * method.matrix[j][l], num_var); 
                dot_add(want, storage, num_var);
            }

            for (int n = 0; n < num_var; ++n) {
                k[j][n] = dxdt[n](want, t[i] + method.nodes[j]*dt, dxdt_param);
            }
            
            constant_multiply(storage, k[j], dt * method.weights[j], num_var);
            dot_add(x_2D[i+1], storage, num_var);
        }
        
        t[i+1] = t[i] + dt;
    }
}
