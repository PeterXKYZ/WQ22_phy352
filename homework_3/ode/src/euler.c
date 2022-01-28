#include <rk_gen.h>
#include <rk_deriv.h>

void euler(double** x, double* t, 
            double (**dxdt) (double* x, double, double*),
            double* dxdt_param, double dt, int steps, int num_var) {

    ButcherTableau method = rk_method_constructor("euler");

    ode_solver(x, t, dxdt, dxdt_param, dt, steps, method, num_var);

    tableau_destroyer(method);
}
