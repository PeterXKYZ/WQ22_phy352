#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <constructors.h>
#include <string_physics.h>
#include <fftw3.h>

#define MAX_X 100
#define MAX_T 1000

const double c = 300;
const double dx = .01;
const double r = 1;

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <mu>\n", argv[0]);
        fprintf(stderr, "where mu = center of Gaussian pulse\n");
        exit(1);
    }

	double dt = (double) (dx / c);
    double mu = strtod(argv[1], NULL);

    // make the 2D array
    double** y_2D = arr_2D_constructor(MAX_T, MAX_X);

    // do the physics
    initialize_with_gauss(y_2D, MAX_X, 1000, mu, dx);
    propagate(y_2D, MAX_T, MAX_X, r);

    // preparing fft
    double* in = (double*) fftw_malloc(sizeof(double) * MAX_T);
	fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * MAX_T);
	fftw_plan p = fftw_plan_dft_r2c_1d(MAX_T, in, out, FFTW_ESTIMATE);

    for (int n = 0; n < MAX_T; ++n) {
		in[n] = y_2D[n][4];
	}

    fftw_execute(p);

    // print the string displacement at x = .05 over time
    // print the fft outputs
    for (int n = 0; n < MAX_T; ++n) {
        printf("t: %lf a: %lf f: %lf re: %lf im: %lf\n", n*dt, in[n],  n/(MAX_T * dt), out[n][0], out[n][1]);
    }

	fftw_destroy_plan(p);
	fftw_free(in);
	fftw_free(out);
	arr_2D_destroyer(y_2D, MAX_X);
    
	return 0;
}
