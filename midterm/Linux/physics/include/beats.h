#ifndef _BEATS_
#define _BEATS_

void initialize_with_free_wave(double** y_2D, int tlen, int xlen, double k, 
                                double dx, double omega, double dt);

void initialize_with_free_wave_sum(double** y_2D, int tlen, int xlen, 
                                double k1, double k2, double dx, 
                                double omega1, double omega2, double dt);

#endif