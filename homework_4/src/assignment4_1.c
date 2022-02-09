#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <constructors.h>
#include <string_physics.h>

#define MAX_X 100
#define MAX_T 100

const double c = 300;
const double dx = .01;
const double r = 1;

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <m>\n", argv[0]);
        fprintf(stderr, "where m = multiples of k\n");
        exit(1);
    }
	double dt = (double) (dx / c);
	double pi = 4 * atan(1);

    // for a standing wave, k = m * pi / L
    // where m = 1,2,3... and L = length of string
    double k_multiplier = strtod(argv[1], NULL);
    double k = k_multiplier * pi / (dx * (MAX_X - 1));

    // make the 2D array
    double** y_2D = arr_2D_constructor(MAX_T, MAX_X);

    // do the physics
    initialize_with_wave(y_2D, MAX_X, k, dx);
    propagate(y_2D, MAX_T, MAX_X, r);

    // print
    // the columns are constant time
    // the rows are constant space
    for (int i = 0; i < MAX_X; ++i) {
        fprintf(stdout, "%lf ", i*dx);
	for (int n = 0; n < MAX_T; ++n) {
            if (n == MAX_T - 1) {
                fprintf(stdout, "%lf\n", y_2D[n][i]);    
            }
            else {
                fprintf(stdout, "%lf ", y_2D[n][i]);
            }
        }
    }

    // kill the 2D array
    arr_2D_destroyer(y_2D, MAX_X);
    return 0;
}
