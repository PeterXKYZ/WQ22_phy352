#ifndef _ASSIGNMENT3_4_PHYSICS_
#define _ASSIGNMENT3_4_PHYSICS_

double dtheta_dt(double* x_1D, double t, double* param);

double domega_dt(double* x_1D, double t, double* param);

int find_extremum(double* x_1D, int max_time);

#endif