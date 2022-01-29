#include <math.h>
#include <assignment3_3_physics.h>

double dtheta_dt(double* x, double t, double* param) {
    // dtheta = omega
    double deriv = x[1];
    return deriv;
}

double domega_dt(double* x, double t, double* param) {
    // domega = -g * theta / l
    double deriv = -param[0] * x[0] / param[1];
    return deriv;
}


double compute_energy(double* x, double* param) {	
	// assuming mass = 1 kg
	double energy = 0.5 * param[1] * param[1] * (x[1] * x[1] + param[0] * x[0] * x[0] / param[1]);
	return energy;
}
