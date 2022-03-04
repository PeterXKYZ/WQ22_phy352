#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include <rk_deriv.h>
#include <constructors.h>
#include <pendulum.h>


const double dt = .01;
const double max_time = 300000;
const int num_var = 2;
const int fd_length = 100;
const int skip_transient = 200;
const int drive_period_count = 300;

static double* linspace(double start, double end, int length) {
    double* arr_1D = arr_1D_constructor(length);
    
    double step = (end - start) / length;
    for (register size_t i = 0; i < length; ++i) {
        arr_1D[i] = start + i*step;
    }

    return arr_1D;
}

int main() {
    const double g_over_l = 1;
    const double q = .5;
    const double omega_D = (double) 2/3;
    const double tau = 8 * atan(1);

    double* F_D = linspace(1.35, 1.5, fd_length);

    // param[0] = g/l, param[1] = q, param[2] = omega_D, param[3] = F_D
    double param[] = {g_over_l, q, omega_D, 0};

    // x_2D[][0] = theta
    // x_2D[][1] = omega
    double** x_2D = arr_2D_constructor(max_time, num_var);
    double* t = arr_1D_constructor(max_time);

    // derivative array
    double (*func[]) (double*, double, double*) = {dtheta_dt, domega_dt};

    // data file 
    FILE* fptr = fopen("data/assignment5_1_data/bifurcation.dat", "w");
    // FILE* fptr2 = fopen("data/assignment5_1_data/pendulum.dat", "w");

    // initial condition
    x_2D[0][0] = 0;
    x_2D[0][1] = 0;
    t[0] = 0;

    
    for (register size_t i = 0; fd_length - i > 0; ++i) {
        param[3] = F_D[i];
        rkO4(x_2D, t, func, param, dt, max_time, num_var);
        
        register size_t j = 0;
        register size_t k = 0;

        while (skip_transient - j > 0 && max_time - k > 0) {
            if ( fabs(fmod(param[2]*t[k], tau)) - .5*dt < 0 ) {
                ++j;
            }
            ++k;
        }

        while (drive_period_count - j > 0 && max_time - k > 0) {
            if ( fabs(fmod(param[2]*t[k], tau)) - .5*dt < 0 ) {
                // angle wrap x_2D[k][0]
                // fprintf(fptr, "F_D: %lf Theta: %lf\n", F_D[i], x_2D[k][0]);
                ++j;
            }
            ++k;
        }
    }
    

    // fclose(fptr2);
    fclose(fptr);
    arr_1D_destroyer(t);
    arr_2D_destroyer(x_2D, max_time);
    arr_1D_destroyer(F_D);
}