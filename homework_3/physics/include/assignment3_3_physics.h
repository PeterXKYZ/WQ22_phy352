#ifndef _ASSIGNMENT3_3_PHYSICS_
#define _ASSIGNMENT3_3_PHYSICS_

double dtheta_dt(double* x_1D, double t, double* param);

double domega_dt(double* x_1D, double t, double* param);

double compute_energy(double* x_1D, double* param);

double analytic_solution(double t, double* param, double* init);

#endif
