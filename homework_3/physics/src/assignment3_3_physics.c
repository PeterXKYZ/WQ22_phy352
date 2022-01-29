#include <assignment3_3_physics.h>

double dtheta_dt(double* x, double t, double* param) {
    // dtheta = omega
    double deriv = x[1];
    return deriv;
}

double domega_dt(double* x, double t, double* param) {
    // domega = -g * theta / l
    double deriv = -param[0] * x[0] / param[1];
    return deriv;
}