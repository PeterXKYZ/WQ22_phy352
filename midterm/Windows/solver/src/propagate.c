#include <propagate.h>

void propagate(double** y_2D, int tlen, int xlen, double r) {
    // y_2D[time][space]
    
    // performs a propagation using the initialized wave
    // as the current waveform and previous waveform
    for (int i = 1; i < (xlen - 1); ++i) {
        y_2D[1][i] = 2*(1-r*r)*y_2D[0][i] - y_2D[0][i] +
                        r*r*(y_2D[0][i+1] + y_2D[0][i-1]);
    }
    
    // numerically solves the 1D wave equation
    for (int n = 1; n < (tlen - 1); ++n) {
        for (int i = 1; i < (xlen - 1); ++i) {
            y_2D[n+1][i] = 2*(1-r*r)*y_2D[n][i] - y_2D[n-1][i] + 
                              r*r*(y_2D[n][i+1] + y_2D[n][i-1]);
        }
    }
}