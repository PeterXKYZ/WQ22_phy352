#include <decay.h>
#include <math.h>

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

double A_exact(double t, double* param) {
    double A_val = 500 * exp(-(param[0] + param[1]) * t) + 500;
    return A_val;
}

double max_relative_err(double** decay_arr, double* time, double* param, int max_time) {
    double prev_error = 0;
    double curr_error = 0;
    double exact = 1;

    for (int i = 0; i < max_time; ++i) {
        exact = A_exact(time[i], param);
        curr_error = fabs( (decay_arr[i][0] - exact) / exact ); 

        if (curr_error > prev_error) {
            prev_error = curr_error;
        }
    }

    return prev_error;
}