#include <stdlib.h>
#include <stdio.h>
#include <beats.h>
#include <propagate.h>
#include <constructors.h>
#include <math.h>
// #include <fftw3.h>

const double c = 300;
const double dx = .01;
const double r = 1;
const double dt = r*dx/c;
const int xlen = 1600;
const int tlen = 800;

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <k> <file path>", argv[0]);
        return 1;
    } 

    double** y_2D = arr_2D_constructor(tlen, xlen);
    
    // argv[1] = k?
    double k = strtod(argv[1], NULL);
    double omega = k*c;
    double pi = 4 * atan(1);

    initialize_with_free_wave(y_2D, tlen, xlen, k, dx, omega, dt);
    propagate(y_2D, tlen, xlen, r);

    // temp print
    for (int i = 0; i < xlen; ++i) {
        printf("%lf ", i*dx);

        for (int n = 0; n < tlen; ++n) {
            printf("%lf ", y_2D[n][i]);
        }

        printf("\n");
    }

    // argv[2] = file path
    FILE* data = fopen(argv[2], "w");

    // preparing fft
    // double* in = (double*) fftw_malloc(sizeof(double) * tlen);
	// fftw_complex* out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * tlen);
	// fftw_plan p = fftw_plan_dft_r2c_1d(tlen, in, out, FFTW_ESTIMATE);
    
    // for (int n = 0; n < tlen; ++n) {
        // in[n] = y_2D[n][5];
    // }

    // fftw_execute(p);

    for (int n = 0; n < tlen; ++n) {
        if (!(fabs(y_2D[n][5]) > .001)) {
            continue;
        }
        fprintf(data, "t: %lf a: %lf f: %lf\n", n*dt, y_2D[n][5], n/(2*pi*tlen*dt));
        // fprint(data, "re: %lf im %lf\n", out[n][0], out[n][1]);
        // in[n] = y_2D[n][5];
    }
    
    // fftw_destroy_plan(p);
	// fftw_free(in);
	// fftw_free(out);
    arr_2D_destroyer(y_2D, tlen);
    return 0;
}