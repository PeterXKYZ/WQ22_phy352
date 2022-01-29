#ifndef _ASSIGNMENT3_3_PHYSICS_
#define _ASSIGNMENT3_3_PHYSICS_

double dtheta_dt(double* x, double t, double* param);
double domega_dt(double* x, double t, double* param);
double compute_energy(double* x, double* param);
double analytic_solution(double t, double* param, double* init);

#endif
