#ifndef _ASSIGNMENT5_2_
#define _ASSIGNMENT5_2_

#include <stdlib.h>

typedef struct 
{
    size_t n;
    double* t;
    double* y;
} data;

int bg_exp_f (const gsl_vector* x, void *data, gsl_vector* f);
int bg_exp_df (const gsl_vector* x, void *data, gsl_matrix* J);

#endif
