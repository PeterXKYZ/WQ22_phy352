#if !defined(_PENDULUM_)
#define _PENDULUM_

#include <math.h>

double dtheta_dt(double* x_1D, double t, double* param);

double domega_dt(double* x_1D, double t, double* param);

#endif // _PENDULUM_
