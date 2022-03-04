#ifndef _ASSIGNMENT5_2_
#define _ASSIGNMENT5_2_

#include <stdlib.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_multifit_nlinear.h>

typedef struct 
{
    size_t n;
    double* t;
    double* y;
} data;

int bg_exp_f (const gsl_vector* x, void *data, gsl_vector* f);
int bg_exp_df (const gsl_vector* x, void *data, gsl_matrix* J);

int sig_f (const gsl_vector* x, void *data, gsl_vector* f);
int sig_df (const gsl_vector* x, void *data, gsl_matrix* J);

int sig_bg_f (const gsl_vector* x, void* dat, gsl_vector* f);
int sig_bg_df (const gsl_vector* x, void* dat, gsl_matrix* J);


#endif
