#include <string_physics.h>
#include <math.h>

void propagate(double** y_2D, int tlen, int xlen, double r) {
    // y_2D[time][space]
    
    // copies the initial waveform to the next time step
    for (int i = 0; i < xlen; ++i) {
        y_2D[1][i] = y_2D[0][i];
    }

    // numerically solves the 1D wave equation
    for (int t = 1; t < (tlen - 1); ++t) {
        for (int x = 1; x < (xlen - 1); ++x) {
            y_2D[t+1][x] = 2*(1-r*r)*y_2D[t][x] - y_2D[t-1][x] + 
                            r*r*(y_2D[t][x+1] + y_2D[t][x-1]);
        }
    }
}

void initialize_with_gauss(double** y_2D, int xlen, double k, double mu, double dx) {
    // gaussian = e^(-k*(x-mu)^2)
    for (int i = 0; i < xlen; ++i) {
        y_2D[0][i] = exp(-k*(i*dx-mu)*(i*dx-mu));
    }
}

void initialize_with_wave(double** y_2D, int xlen, double k, double dx) {
    // wave = sin(k*x) where k = 2*pi / lambda 
    for (int i = 0; i < xlen; ++i) {
        y_2D[0][i] = sin(k*i*dx);
    }
}