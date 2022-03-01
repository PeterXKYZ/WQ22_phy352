#include <stdlib.h>

#include <constructors.h>
#include <rk_gen.h>


static void constant_multiply(double* dst, const double* a, double s, int length) {
    for (register size_t i = 0; length - i > 0 ; ++i) {
        dst[i] = a[i] * s;
    }
}

static void dot_add(double* a, const double* b, int length) {
    for (register size_t i = 0; length - i > 0; ++i) {
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

    for (register size_t i = 0; steps-1-i > 0; ++i) {

        for (register size_t n = 0; num_var - n > 0; ++n) {
            x_2D[i+1][n] = x_2D[i][n];
        }
        
        for (register size_t j = 0; method.order - j > 0; ++j) {
            for (register size_t m = 0; num_var - m > 0; ++m) {
                want[m] = x_2D[i][m];
            }

            for (register size_t l = 0; j - l > 0; ++l) {
                constant_multiply(storage, k[l], dt * method.matrix[j][l], num_var); 
                dot_add(want, storage, num_var);
            }

            for (register size_t n = 0; num_var - n > 0; ++n) {
                k[j][n] = dxdt[n](want, t[i] + method.nodes[j]*dt, dxdt_param);
            }
            
            constant_multiply(storage, k[j], dt * method.weights[j], num_var);
            dot_add(x_2D[i+1], storage, num_var);
        }
        
        t[i+1] = t[i] + dt;
    }
}
