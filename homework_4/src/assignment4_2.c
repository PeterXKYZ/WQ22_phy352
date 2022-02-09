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

int main(void) {
	double dt = (double) (dx / c);

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

// ------------------------------------------------------------

	double* in = (double*) fftw_malloc(sizeof(double) * MAX_T);
	fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * MAX_T);
	fftw_plan p = fftw_plan_dft_r2c_1d(MAX_T, in, out, FFTW_ESTIMATE);

	for (int n = 0; n < MAX_T; ++n) {
		in[n] = y_2D[n][4];
	}
	
	fftw_execute(p);
	
	FILE* data2 = fopen("data/assignment4_2_data/fft_test.dat", "w");

	for (int n = 0; n < MAX_T; ++n) {
		fprintf(data2, "%lf %lf %lf\n", n/(MAX_T * dt), out[n][0], out[n][1]);
	}

	fclose(data2);
	fftw_destroy_plan(p);
	fftw_free(in);
	fftw_free(out);
	arr_2D_destroyer(y_2D, MAX_X);
    
	return 0;
}
