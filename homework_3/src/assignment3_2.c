#include <math.h>
#include <constructors.h>
#include <stdlib.h>

#define MAX_TIME 20
#define NUM_VAR 4


int main(int argc, char* argv[]) {
    double pi = 4 * atan(1);
    double ang_deg = strtod(argv[0], NULL);
    double ang_rad = ang_deg * pi / 180;
    
    double init_v = 700 // initial_velocity 700 m/s 
    double init_vx = init_v * cos(ang_rad);
    double init_vy = init_v * sin(ang_rad);

    double dt = 0.1;

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

    double* t = t_constructor(MAX_TIME, 0);
    double** x = x_constructor(NUM_VAR, MAX_TIME, x_init);

    t_destroyer(t);
    x_destroyer(x, MAX_TIME);
}
