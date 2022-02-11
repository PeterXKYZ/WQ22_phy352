#include <decay.h>

// x_1D[0] = A, x_1D[1] = B
// param[0] = τ1, param[1] = τ2
double dAdt(double* x_1D, double t, double* param) {
    // dAdt = -A / τ1 + B / τ2 
    double deriv = -x_1D[0] / param[0] + x_1D[1] / param[1];
    return deriv;
}

double dBdt(double* x_1D, double t, double* param) {
    // dBdt = -B / τ1 + A / τ2
    double deriv = -x_1D[1] / param[1] + x_1D[0] / param[0];
    return deriv;
}