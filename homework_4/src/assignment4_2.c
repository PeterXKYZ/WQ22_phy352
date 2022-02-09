#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <constructors.h>
#include <string_physics.h>

#define MAX_X 100
#define MAX_T 1000

const double c = 300;
const double dx = .01;
const double dt = (double) (dx / c);
const double r = 1;

int main(void) {
    // make the 2D array
    double** y_2D = arr_2D_constructor(MAX_T, MAX_X);

    // do the physics
    initialize_with_gauss(y_2D, MAX_X, 1000, .5, dx);
    propagate(y_2D, MAX_T, MAX_X, r);

    FILE* data = fopen("data/assignment4_2_data/string_data.dat", "w");

    // print the string displacement at x = .05 over time
    for (int n = 0; n < MAX_T; ++n) {
        fprintf(data, "%lf %lf\n", n*dt, y_2D[n][4]);
    }

    fclose(data);
    arr_2D_destroyer(y_2D, MAX_X);
    return 0;
}