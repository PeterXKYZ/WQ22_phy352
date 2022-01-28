#include <rk_gen.h>
#include <rk_deriv.h>

void rk02(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, 
            ButcherTableau method, int num_var) {

    ButcherTableau method = rk_method_constructor("mid_point");

    ode_solver(x, t, dxdt, dxdt_param, dt, steps, method, num_var);

    tableau_destroyer(method);
}