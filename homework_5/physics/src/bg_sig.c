#include <assignment5_2.h>
#include <math.h>

int sig_bg_f (const gsl_vector* x, void* dat, gsl_vector* f)
{
    data* dptr = (data*) dat;
    size_t n = dptr->n;
    double* t = dptr->t;
    double* y = dptr->y;

    double As = gsl_vector_get(x, 0);
    double mu = gsl_vector_get(x, 1);
    double sigma = gsl_vector_get(x, 2);

    double Ab = gsl_vector_get(x, 3);
    double tau = gsl_vector_get(x, 4);

    for (size_t i = 0; i < n; i++) {
        double Yi = Ab * exp((t[i] - 100) / tau) + As*exp(-.5*(t[i]-mu)*(t[i]-mu)/(sigma*sigma));
        gsl_vector_set (f, i, Yi - y[i]);
    }

    return GSL_SUCCESS;
}

int sig_bg_df (const gsl_vector* x, void* dat, gsl_matrix* J)
{
    data* dptr = (data*) dat;
    size_t n = dptr->n;
    double* t = dptr->t;

    double As = gsl_vector_get(x, 0);
    double mu = gsl_vector_get(x, 1);
    double sigma = gsl_vector_get(x, 2);

    double Ab = gsl_vector_get(x, 3);
    double tau = gsl_vector_get(x, 4);

    for (size_t i = 0; i < n; i++) {
        double e = exp(-.5*(t[i]-mu)*(t[i]-mu)/(sigma*sigma)); 
        double e2 = exp((t[i] - 100) / tau);
        gsl_matrix_set(J, i, 0, e);
        gsl_matrix_set(J, i, 1, As*e*(t[i]-mu)/(sigma*sigma));
        gsl_matrix_set(J, i, 2, As*e*(t[i]-mu)*(t[i]-mu)/(sigma*sigma*sigma));
        gsl_matrix_set(J, i, 3, e2);
        gsl_matrix_set(J, i, 4, -Ab*(t[i]-100)*e2/(tau*tau));
    }

    return GSL_SUCCESS;
}
