#include <math.h>
#include <beats.h>

void initialize_with_free_wave(double** y_2D, int tlen, int xlen, double k, 
                                double dx, double omega, double dt) {
    // y_2D[time][space]
    for (int n = 0; n < tlen; ++n) {
        y_2D[n][0] = sin(-omega*dt*n);  // x = 0
        y_2D[n][xlen-1] = sin(k*dx*(xlen-1) - omega*dt*n);
    }

    for (int i = 1; i < xlen-1; ++i) {
        y_2D[0][i] = 0;
    }
}

void initialize_with_free_wave_sum(double** y_2D, int tlen, int xlen, 
                                double k1, double k2, double dx, 
                                double omega1, double omega2, double dt) {
    // y_2D[time][space]
    for (int n = 0; n < tlen; ++n) {
        y_2D[n][0] = sin(-omega1*dt*n) + sin(-omega2*dt*n);
        y_2D[n][xlen-1] = sin(k1*dx*(xlen-1) - omega1*dt*n) 
                        + sin(k2*dx*(xlen-1) - omega2*dt*n);
    }

    for (int i = 1; i < xlen-1; ++i) {
        y_2D[0][i] = 0;
    }
}