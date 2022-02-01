#ifndef _RKGEN_
#define _RKGEN_

#include "constructors.h"

void ode_solver(double** x_2D, double* t, 
                double (**dxdt) (double* x_1D, double t, double* param),
                double* dxdt_param, double dt, int steps, 
                ButcherTableau method, int num_var);

#endif