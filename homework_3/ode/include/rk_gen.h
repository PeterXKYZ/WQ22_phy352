#ifndef _RKGEN_
#define _RKGEN_

#include "constructors.h"

void ode_solver(double** x, double* t, 
                double (**dxdt) (double* x, double, double*),
                double* dxdt_param, double dt, int steps, 
                ButcherTableau method, int num_var);

#endif