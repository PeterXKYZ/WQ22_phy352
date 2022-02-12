#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include <rk_gen.h>
#include <decay.h>
#include <constructors.h>

const int num_var = 2;

int main(int argc, char** argv) {
    // check command line arguments to see if 
    // we want to find and print max error
    bool find_max;
    if (argc == 3) {
        find_max = false;   
    }
    else if (argc == 4) {
        find_max = true;
    }
    else {
        fprintf(stderr, "Usage: %s <method> <time step> <print?>", argv[0]);
        return 2;
    }
    
    // argv[1] = method selector
    ButcherTableau method;

    if (strcmp(argv[1], "euler") == 0) {
        method = rk_method_constructor("euler");
    }
    else if (strcmp(argv[1], "rkO2") == 0) {
        method = rk_method_constructor("mid_point");
    }
    else if (strcmp(argv[1], "rkO4") == 0) {
        method = rk_method_constructor("classic_rk");
    }
    else {
        fprintf(stderr, "%s is not a recognized solver method!", argv[1]);
        return 1;
    }

    // argv[2] = time step
    double dt = strtod(argv[2], NULL);
    int max_time = (int) ceil(5 / dt);

    // derivative array
    double (*func[]) (double*, double, double*) = {dAdt, dBdt};

    // decay array
    double** decay_count_2D = arr_2D_constructor(max_time, num_var);

    // time array
    double* time = arr_1D_constructor(max_time);

    // initial conditions
    // A(t=0) = 1000, B(t=0) = 0
    decay_count_2D[0][0] = 1000;
    decay_count_2D[0][1] = 0; 
    time[0] = 0;

    // params
    // param[0] = τ1, param[1] = τ2
    double param[] = {1, 1};

    // solving time!
    ode_solver(decay_count_2D, time, func, param, dt, max_time, method, num_var);

    if (find_max) {
        // compute the max relative error
        double max_error = max_relative_err(decay_count_2D, time, param, max_time);

        // print the output (for now)
        printf("time_steps: %i max_error: %E ", max_time, max_error);
    }

    tableau_destroyer(method);
    arr_2D_destroyer(decay_count_2D, max_time);
    return 0;
}