#ifndef _DECAY_
#define _DECAY_

double dAdt(double* x_1D, double t, double* param);
double dBdt(double* x_1D, double t, double* param);
double A_exact(double t, double* param);
double max_relative_err(double** decay_arr, double* time, double* param, int max_time);

#endif