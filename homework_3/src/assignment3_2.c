#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <constructors.h>
#include <assignment3_2_physics.h>
#include <rk_deriv.h>

#define MAX_TIME 300
#define NUM_VAR 4


int main(int argc, char* argv[]) {
    // angle will be determined by argument passed to main
    if (argc != 2) {
        fprintf(stderr, "Format: %s <angle in degrees>", argv[0]);
        exit(1);
    }
    
    double pi = 4 * atan(1);
    double ang_deg = strtod(argv[1], NULL);
    double ang_rad = ang_deg * pi / 180;
    
    // initial_velocity of 700 m/s
    double init_v = 700; 
    double init_vx = init_v * cos(ang_rad);
    double init_vy = init_v * sin(ang_rad);

    double dt = .5;

    // fparam[0] = g (gravitational constant) = 9.81 m/s
    // fparam[1] = m (mass) = 1 kg
    // fparam[2] = B2 (drag coefficient) = 4 x 10^-5 kg/m
    // fparam[3] = a (atmospheric constant) = 6.5 x 10^-3 K/m
    // fparam[4] = alpha (atmospheric exponent) = 2.5
    // fparam[5] = T0 (sea level temperature) = 300 K
    double fparam[] = {9.81, 1, 4E-5, 6.5E-3, 2.5, 300};

    // x[0] = x
    // x[1] = dx/dt = vx
    // x[2] = y
    // x[3] = dy/dt = vy
    double x_init[] = {0, init_vx, 0, init_vy};

    double (*func[NUM_VAR]) (double*, double, double*);
    func[0] = dxdt;
    func[1] = dvxdt;
    func[2] = dydt;
    func[3] = dvydt;

    double* t = t_constructor(MAX_TIME, 0);
    double** x = x_constructor(NUM_VAR, MAX_TIME, x_init);

    rkO4(x, t, func, fparam, dt, MAX_TIME, NUM_VAR);
    
    for (int i = 0; i < MAX_TIME && x[i][2] > -0.00001; ++i) {
        printf("%lf\t%lf\n", x[i][0], x[i][2]);
    }

    t_destroyer(t);
    x_destroyer(x, MAX_TIME);
}
