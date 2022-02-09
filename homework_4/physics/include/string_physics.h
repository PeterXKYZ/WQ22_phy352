#ifndef _STRING_PHYSICS_
#define _STRING_PHYSICS_

// numerically solves the 1D wave equation
// y_2D must be initialized with a waveform at time t = 0
void propagate(double** y_2D, int tlen, int xlen, double r);

// initializes y_2D at t = 0 with a gaussian function where
// y_2D[0] = e^(-k*(x-mu)^2)
void initialize_with_gauss(double** y_2D, int xlen, double k, double mu, double dx);

// initializes y_2D at t = 0 with a sine wave where
// y_2D[0] = sin(k*x)
// for a standing wave, set k = m*pi / L 
// where m = 1,2,3... and L = length of string 
void initialize_with_wave(double** y_2D, int xlen, double k, double dx);

#endif