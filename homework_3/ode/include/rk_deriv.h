#ifndef _RKDERIV_
#define _RKDERIV_

#include "constructors.h"

void euler(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, 
            ButcherTableau method, int num_var);

void rk02(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, 
            ButcherTableau method, int num_var);

void rk04(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, 
            ButcherTableau method, int num_var);

#endif