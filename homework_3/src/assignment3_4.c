#include <assignment3_4_physics.h>
#include <rk_deriv.h>
#include <stdio.h>
#include <math.h>

#define MAX_TIME 2001
#define NUM_VAR 2
#define OMEGA_POINTS 101
#define Q_POINTS 41

int main(void) {
    // double tic = clock();   // how fast does this code run?

    double (*func[NUM_VAR]) (double*, double, double*);
    func[0] = dtheta_dt;
    func[1] = domega_dt;

    double dt = .01;

    // range of omega values to scan over
    double omega_arr[OMEGA_POINTS];
    omega_arr[0] = sqrt(9.81);
    for (int i = 1; i < OMEGA_POINTS-1; i += 2) {
        omega_arr[i] = omega_arr[0] + .03*i;
        omega_arr[i+1] = omega_arr[0] - .03*i; 
    }

    // range of q values to scan over
    double q_arr[Q_POINTS];
    for (int i = 0; i < Q_POINTS; i++) {
        q_arr[i] = .1 + .2*i;
    } 

    // param[0] = sqrt(g/l) = Omega 
    // param[1] = q
    // param[2] = F_d
    // param[3] = Omega_d
    double param[] = {sqrt(9.81), 1, .2, .667};

    // x[0] = theta, x[1] = omega
    // the driving force will make it move
    double x_init[] = {0, 0};

    // constructing the x_2D and t array
    double* t = t_constructor(MAX_TIME, 0);
    double** x = x_constructor(NUM_VAR, MAX_TIME, x_init);

    // make a 1D array to store just the angle information
    double angles[MAX_TIME];

    // ----------------------------scan over Omega_d----------------------------------------

    FILE* data1 = fopen("data/assignment3_4_data/assignment3_4_Omega.dat", "w");

    for (int i = 0; i < OMEGA_POINTS; ++i) {
        param[3] = omega_arr[i]; // set Omega_d to one of the values in array
        rkO4(x, t, func, param, dt, MAX_TIME, NUM_VAR);

        for (int j = 0; j < MAX_TIME; ++j) {
            angles[j] = x[j][0];
        }

        int ind = find_extremum(angles, MAX_TIME); // find the steady-state amplitude

        fprintf(data1, "%lf %lf\n", omega_arr[i], fabs(angles[ind])); // fabs = float absolute value
    }

    fclose(data1);
    
    // ---------------------------scan over q----------------------------------------------

    FILE* data2 = fopen("data/assignment3_4_data/assignment3_4_q.dat", "w");
    param[3] = sqrt(9.81);    // set Omega_d back to resonance freq

    for (int i = 0; i < Q_POINTS; ++i) {
        param[1] = q_arr[i];
        rkO4(x, t, func, param, dt, MAX_TIME, NUM_VAR);

        for (int j = 0; j < MAX_TIME; ++j) {
            angles[j] = x[j][0];
        }

        int ind = find_extremum(angles, MAX_TIME);

        fprintf(data2, "%lf %lf\n", q_arr[i], fabs(angles[ind]));
    }

    fclose(data2);

    // ----------------------destroy everything------------------------------

    t_destroyer(t);
    x_destroyer(x, MAX_TIME);

    /*
    double toc = clock();
    double time = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("%lf", time);
    */

    return 0;
}
