#ifndef _RKDERIV_
#define _RKDERIV_

#include "constructors.h"

void euler(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, int num_var);

void rkO2(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, int num_var);

void rkO4(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, int num_var);

#endif
