#include <assignment5_2.h>
#include <math.h>

int bg_exp_f (const gsl_vector* x, void* dat, gsl_vector* f)
{
    data* dptr = (data*) dat;
    size_t n = dptr->n;
    double* t = dptr->t;
    double* y = dptr->y;

    double Ab = gsl_vector_get(x, 0);
    double tau = gsl_vector_get(x, 1);

    for (size_t i = 0; i < n; i++) {
        double Yi = Ab * exp((t[i] - 100) / tau);
        gsl_vector_set (f, i, Yi - y[i]);
    }

    return GSL_SUCCESS;
}

int bg_exp_df (const gsl_vector* x, void* dat, gsl_matrix* J)
{
    data* dptr = (data*) dat;
    size_t n = dptr->n;
    double* t = dptr->t;

    double Ab = gsl_vector_get(x, 0);
    double tau = gsl_vector_get(x, 1);

    for (size_t i = 0; i < n; i++) {
        double e = exp((t[i] - 100) / tau); 
        gsl_matrix_set(J, i, 0, e);
        gsl_matrix_set(J, i, 1, -Ab*(t[i]-100)*e/(tau*tau));
    }

    return GSL_SUCCESS;
}
