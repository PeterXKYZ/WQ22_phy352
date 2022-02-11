#include <rk_gen.h>
#include <rk_deriv.h>

void rkO4(double** x_2D, double* t, 
            double (**dxdt) (double* x_1D, double t, double* param),
            double* dxdt_param, double dt, int steps, int num_var) {

    ButcherTableau method = rk_method_constructor("classic_rk");

    ode_solver(x_2D, t, dxdt, dxdt_param, dt, steps, method, num_var);

    tableau_destroyer(method);
}
