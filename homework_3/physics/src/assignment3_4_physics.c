#include <math.h>
#include <assignment3_4_physics.h>

double dtheta_dt(double* x_1D, double t, double* param) {
    // d_theta = omega
    double deriv = x_1D[1];
    return deriv;
}

double domega_dt(double* x_1D, double t, double* param) {
    // damped and forced simple harmonic oscillator
    // d_omega = -Omega^2 * theta - q*omega + F_D * sin(Omega_d * t)
    double deriv = -param[0]*param[0]*x_1D[0] - param[1]*x_1D[1] + param[2]*sin(param[3]*t);
    return deriv;
}

// find the first extremum starting from the end of an array
// returns the index where the extremum occurs
int find_extremum(double* x_1D, int max_time) {
    for (int i = max_time-1; i >= 2; --i) {
        double diff1 = x_1D[i] - x_1D[i-1];
        double diff2 = x_1D[i-1] - x_1D[i-2];

        // diff1 * diff < 0 means diff1 and diff2 have different signs
        // that means the slope changed from pos to neg or vice versa
        // then we found an extremum
        if (diff1 * diff2 < 0) {
            return i-1;
        }
    }

    // if we don't find any extremum, return 0
    return 0;
}