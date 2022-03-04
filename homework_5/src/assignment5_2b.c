#include <stdlib.h>
#include <stdio.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multifit_nlinear.h>

#include <utils.h>
#include <assignment5_2.h>

#define N 60    // the number of data points to fit
#define P 3     // the number of parameters in model function


int main() {
    // used to solve the trust region problem, no idea what that means
    const gsl_multifit_nlinear_type* T = gsl_multifit_nlinear_trust;

    // get defaults parameters
    gsl_multifit_nlinear_parameters fdf_params =
        gsl_multifit_nlinear_default_parameters();

    // allocate workspace with default paramters
    gsl_multifit_nlinear_workspace* w =
        gsl_multifit_nlinear_alloc(T, &fdf_params, N, P);   

    // -------------------------------------------------------------------------------
    // params?
    double t[N];
    double y[N];
    double weights[N];

    data d = {N, t, y};

    // starting values
    // As, sigma, mu
    double x_init[P] = {100, 100, 10};
    gsl_vector_view x = gsl_vector_view_array (x_init, P);
    gsl_vector_view wts = gsl_vector_view_array(weights, N);

    // chi-squared values
    double chisq;
    double chisq0;
    int status;
    int info;

    // tolerances
    const double xtol = 1e-8;
    const double gtol = 1e-8;
    const double ftol = 0.0;

    // ------------------------------------------------------------------------------
    // we provide the function to be minimized here
    gsl_multifit_nlinear_fdf fdf;

    // a function of type int (*f) (const gsl_vector* x, void* params, gsl_vector* f)
    fdf.f = sig_f;   

    // stores the n-by-p Jacobian matrix J_ij = pd(f_i)(x_j)
    // int (*f) (const gsl_vector* x, void* params, gsl_matrix* J)
    fdf.df = sig_df;

    // set to NULL for no geodesic acceleration
    fdf.fvv = NULL;

    // matrix size
    fdf.n = N;
    fdf.p = P;
    fdf.params = &d;


    // read in the data
    size_t i = 0;
    double tmpt, tmpy, tmpw;
    FILE * fh = fopen("data/assignment5_2_data/higgs.dat", "r");
    printf("reading file %s\n", "higgs.dat");
    while( fscanf(fh, "%lf\t%lf\t%lf\n", &tmpt, &tmpy, &tmpw  ) != EOF ){ 
        printf( "t: %lf\ty: %lf\tw: %lf\n", tmpt, tmpy, tmpw );
        t[i] = tmpt;
        y[i] = tmpy;
        weights[i] = 1./(tmpw*tmpw); //dummy value tmpw
        i++;
    }
    fclose(fh);

    // ------------------------------------------------------------------------------
    // a Jacobian matrix and cost function
    gsl_vector* f;
    gsl_matrix* J;
    gsl_matrix* covar = gsl_matrix_alloc (P, P);

    // ------------------------------------------------------------------------------
    // random generator
    gsl_rng_env_setup();
    gsl_rng* r = gsl_rng_alloc(gsl_rng_default);

    // ------------------------------------------------------------------------------
    // initialize solver with starting point and weights
    gsl_multifit_nlinear_winit (&x.vector, &wts.vector, &fdf, w);

    // compute initial cost function
    f = gsl_multifit_nlinear_residual(w);
    gsl_blas_ddot(f, f, &chisq0);

    // solve the system with a maximum of 100 iterations
    printf("hello\n");
    status = gsl_multifit_nlinear_driver(100, xtol, gtol, ftol,
                                        callbackSIG, NULL, &info, w);

    // compute covariance of best fit parameters
    J = gsl_multifit_nlinear_jac(w);
    gsl_multifit_nlinear_covar (J, 0.0, covar);

    // compute final cost
    gsl_blas_ddot(f, f, &chisq);

    // -------------------------------------------------------------------------------
    // printing stuff I don't understand
    #define FIT(i) gsl_vector_get(w->x, i)
    #define ERR(i) sqrt(gsl_matrix_get(covar,i,i))

    fprintf(stdout, "summary from method '%s/%s'\n",
            gsl_multifit_nlinear_name(w),
            gsl_multifit_nlinear_trs_name(w));
    fprintf(stdout, "number of iterations: %zu\n",
            gsl_multifit_nlinear_niter(w));
    fprintf(stdout, "function evaluations: %zu\n", fdf.nevalf);
    fprintf(stdout, "Jacobian evaluations: %zu\n", fdf.nevaldf);
    fprintf(stdout, "reason for stopping: %s\n",
            (info == 1) ? "small step size" : "small gradient");
    fprintf(stdout, "initial |f(x)| = %f\n", sqrt(chisq0));
    fprintf(stdout, "final   |f(x)| = %f\n", sqrt(chisq));

    {
        double dof = N - P;
        double c = GSL_MAX_DBL(1, sqrt(chisq / dof));

        fprintf(stdout, "chisq/dof = %g\n", chisq / dof);

        fprintf (stdout, "As     = %.5f +/- %.5f\n", FIT(0), c*ERR(0));
        fprintf (stdout, "mu    = %.5f +/- %.5f\n", FIT(1), c*ERR(1));
        fprintf (stdout, "sigma    = %.5f +/- %.5f\n", FIT(2), c*ERR(2));
    }

    fprintf (stdout, "status = %s\n", gsl_strerror (status));

    // ------------------------------------------------------------------------------
    // free all the shit
    gsl_multifit_nlinear_free (w);
    gsl_matrix_free (covar);
    gsl_rng_free (r);

    return 0;
}
