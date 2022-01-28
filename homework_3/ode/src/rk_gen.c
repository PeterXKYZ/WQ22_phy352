#include <stdio.h>
#include <stdlib.h>

#include <constructors.h>
#include <rk_gen.h>

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
