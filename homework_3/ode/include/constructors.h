#ifndef _CONSTRUCTORS_
#define _CONSTRUCTORS_

typedef struct{
    int order;
    double* weights;    // pointer to a double array created by malloc
    double* nodes;      // pointer to a double array created by malloc
    double** matrix;    // pointer to a pointer array created by malloc
} ButcherTableau;

// return a ButcherTableau corresponding to the given name
// "euler": euler method
// "mid_point": rk02 method
// "classic_rk": rk04 method
ButcherTableau rk_method_constructor(char* name);

// free all pointers in ButcherTableau
void tableau_destroyer(ButcherTableau method);

// return a double array created by malloc with length 'max_time'
// first element initialized to 'init'
double* t_constructor(int max_time, double init);

// free the time array
void t_destroyer(double* t);

// return a pointer array created by malloc  
// dimensions: [max_time][num_var] 
//  { { }, { }, ... { } }
//  |       ^           | 
//  |    num_var        |
//  |___________________| <- max_time
double** x_constructor(int num_var, int max_time, double* init);

// free all the pointers in 'x'
void x_destroyer(double** x, int max_time);

#endif



