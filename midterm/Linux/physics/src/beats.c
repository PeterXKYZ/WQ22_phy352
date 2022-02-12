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