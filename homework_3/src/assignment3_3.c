#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <constructors.h>
#include <assignment3_3_physics.h>
#include <rk_deriv.h>

#define MAX_TIME 300
#define NUM_VAR 2

int main(void) {
    double pi = 4 * atan(1);
    double dt = .05;

    // omega = -g * theta / l
    // param[0] = g
    // param[1] = l
    double param[] = {9.81, 1};

    // initial angle = 20
    double ang_deg = 20;
    double ang_rad = ang_deg * pi / 180;

    // x[][0] = theta, x[][1] = omega
    double x_init[] = {ang_rad, 0};

    // derivatives
    double (*func[NUM_VAR]) (double*, double, double*);
    func[0] = dtheta_dt;
    func[1] = domega_dt;

    double* t = t_constructor(MAX_TIME, 0);
    double** x_euler = x_constructor(NUM_VAR, MAX_TIME, x_init);
    double** x_rkO2 = x_constructor(NUM_VAR, MAX_TIME, x_init);
    double** x_rkO4 = x_constructor(NUM_VAR, MAX_TIME, x_init);

    euler(x_euler, t, func, param, dt, MAX_TIME, NUM_VAR);
    t[0] = 0;
    rkO2(x_rkO2, t, func, param, dt, MAX_TIME, NUM_VAR);
    t[0] = 0;
    rkO4(x_rkO4, t, func, param, dt, MAX_TIME, NUM_VAR);

    // files?
    FILE* angle_dat = fopen("data/assignment3_3_data/assignment3_3_angle.dat", "w");
    FILE* energy_dat = fopen("data/assignment3_3_data/assignment3_3_energy.dat", "w");
    FILE* error_dat = fopen("data/assignment3_3_data/assignment3_3_error.dat", "w");
    
    if (!angle_dat || !energy_dat || !error_dat) {
        fprintf(stderr, "Can't write to location!\n");
        exit(1);
    }

    double solution[MAX_TIME];
    
    for (int i = 0; i < MAX_TIME; ++i) {
        solution[i] = analytic_solution(t[i], param, x_init);

        fprintf(angle_dat, "t: %lf euler: %lf rkO2: %lf rkO4: %lf anal: %lf\n", 
                t[i], x_euler[i][0], x_rkO2[i][0], x_rkO4[i][0], solution[i]);

        fprintf(energy_dat, "t: %lf energy_e: %lf energy_O2: %lf energy_O4: %lf\n", 
                t[i], compute_energy(x_euler[i], param), compute_energy(x_rkO2[i], param), compute_energy(x_rkO4[i], param));
                
        fprintf(error_dat, "t: %lf error_e: %lf error_O2: %lf error_O4: %lf\n",
                t[i], (x_euler[i][0] - solution[i]) / solution[i], 
                (x_rkO2[i][0] - solution[i]) / solution[i], 
                (x_rkO4[i][0] - solution[i]) / solution[i]);   
    }
    
    fclose(angle_dat);
    fclose(energy_dat);
    fclose(error_dat);

    t_destroyer(t);
    x_destroyer(x_euler, MAX_TIME);
    x_destroyer(x_rkO2, MAX_TIME);
    x_destroyer(x_rkO4, MAX_TIME);
    return 0;
} 
