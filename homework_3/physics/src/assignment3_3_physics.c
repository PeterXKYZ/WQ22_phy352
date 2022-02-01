#include <math.h>
#include <assignment3_3_physics.h>

double dtheta_dt(double* x_1D, double t, double* param) {
    // dtheta = omega
    double deriv = x_1D[1];
    return deriv;
}

double domega_dt(double* x_1D, double t, double* param) {
    // domega = -g * theta / l
    double deriv = -param[0] * x_1D[0] / param[1];
    return deriv;
}


double compute_energy(double* x_1D, double* param) {	
	// assuming mass = 1 kg
    // using small angle approximation
	double energy = 0.5 * param[1] * param[1] * (x_1D[1] * x_1D[1] + param[0] * x_1D[0] * x_1D[0] / param[1]);
	return energy;
}

double analytic_solution(double t, double* param, double* init) {
    double theta = init[0] * cos( sqrt(param[0] / param[1]) * t ) + 
                   init[1] * sin( sqrt(param[0] / param[1]) * t ) * sqrt(param[1] / param[0]);

    return theta;
}
