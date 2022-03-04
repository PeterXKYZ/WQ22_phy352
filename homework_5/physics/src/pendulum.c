#include <pendulum.h>

double dtheta_dt(double* x_1D, double t, double* param) {
    // x_1D[0] = theta
    // x_1D[1] = omega
    return x_1D[1];
}

double domega_dt(double* x_1D, double t, double* param) {
    // x_1D[0] = theta
    // x_1D[1] = omega
    // param[0] = g/l, param[1] = q, param[2] = omega_D, param[3] = F_D
    double deriv = -param[0]*sin(x_1D[0]) - param[1]*x_1D[1] + param[3]*sin(param[2] * t);
    return deriv;
}