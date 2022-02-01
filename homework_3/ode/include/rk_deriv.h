#ifndef _RKDERIV_
#define _RKDERIV_

#include "constructors.h"

void euler(double** x_2D, double* t, 
            double (**dxdt) (double* x_1D, double t, double* param),
            double* dxdt_param, double dt, int steps, int num_var);

void rkO2(double** x_2D, double* t, 
            double (**dxdt) (double* x_1D, double t, double* param),
            double* dxdt_param, double dt, int steps, int num_var);

void rkO4(double** x_2D, double* t, 
            double (**dxdt) (double* x_1D, double t, double* param),
            double* dxdt_param, double dt, int steps, int num_var);

#endif
