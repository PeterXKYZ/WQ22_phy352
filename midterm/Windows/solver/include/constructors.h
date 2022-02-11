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
double* arr_1D_constructor(int arr_len);

// free the time array
void arr_1D_destroyer(double* arr_1D);

// return a pointer array created by malloc  
// dimensions: [arr_len][sub_arr_len] 
//  { { }, { }, ... { } }
//  |       ^           | 
//  |  sub_arr_len      |
//  |___________________| <- arr_len
double** arr_2D_constructor(int arr_len, int sub_arr_len);

// free all the pointers in 'arr_2D'
void arr_2D_destroyer(double** arr_2D, int arr_len);

#endif



