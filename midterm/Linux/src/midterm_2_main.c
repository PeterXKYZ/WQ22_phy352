#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <beats.h>
#include <propagate.h>
#include <constructors.h>
#include <math.h>
#include <fftw3.h>

const double c = 300;
const double dx = .01;
const double r = 1;
const int xlen = 1600;
const int tlen = 800;
const double k1 = 4;
const double k2 = 4.4;

int main(void) {
    double pi = 4 * atan(1);
	double omega1 = k1*c*2*pi;
    double omega2 = k2*c*2*pi;
	double dt = r*dx/c;

    // arrays
    double** y_k1_2D = arr_2D_constructor(tlen, xlen);
    double** y_k2_2D = arr_2D_constructor(tlen, xlen);
    double** y_k12_2D = arr_2D_constructor(tlen, xlen);
    
    // gif data files
    FILE* prop_k1 = fopen("data/midterm_2_data/wave_prop_k1.dat", "w");
    FILE* prop_k2 = fopen("data/midterm_2_data/wave_prop_k2.dat", "w");
    FILE* add_k12 =  fopen("data/midterm_2_data/wave_add_k12.dat", "w");
    FILE* prop_k12 = fopen("data/midterm_2_data/wave_prop_k12.dat", "w");

    initialize_with_free_wave(y_k1_2D, tlen, xlen, k1, dx, omega1, dt);
    initialize_with_free_wave(y_k2_2D, tlen, xlen, k2, dx, omega2, dt);
    initialize_with_free_wave_sum(y_k12_2D, tlen, xlen, k1, k2, dx, omega1, omega2, dt);

    propagate(y_k1_2D, tlen, xlen, r);
    propagate(y_k2_2D, tlen, xlen, r);
    propagate(y_k12_2D, tlen, xlen, r);

    // gif animation data
    for (int i = 0; i < xlen; ++i) {
        fprintf(prop_k1, "%lf ", i*dx);
        fprintf(prop_k2, "%lf ", i*dx);
        fprintf(add_k12, "%lf ", i*dx);
        fprintf(prop_k12, "%lf ", i*dx);

        for (int n = 0; n < tlen; ++n) {
            fprintf(prop_k1, "%lf ", y_k1_2D[n][i]);
            fprintf(prop_k2, "%lf ", y_k2_2D[n][i]);
            fprintf(add_k12, "%lf ", y_k1_2D[n][i] + y_k2_2D[n][i]);
            fprintf(prop_k12, "%lf ", y_k12_2D[n][i]);
        }

        fprintf(prop_k1, "\n");
        fprintf(prop_k2, "\n");
        fprintf(add_k12, "\n");
        fprintf(prop_k12, "\n");
    }

    // fft files
    FILE* fft_k1 = fopen("data/midterm_2_data/fft_k1.dat", "w");
    FILE* fft_k2 = fopen("data/midterm_2_data/fft_k2.dat", "w");
    FILE* fft_add_k12 = fopen("data/midterm_2_data/fft_add_k12.dat", "w");

    // preparing fft
    double* in_1 = (double*) fftw_malloc(sizeof(double) * tlen);
    fftw_complex* out_1 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * tlen);
	fftw_plan p_1 = fftw_plan_dft_r2c_1d(tlen, in_1, out_1, FFTW_ESTIMATE);

    double* in_2 = (double*) fftw_malloc(sizeof(double) * tlen);
    fftw_complex* out_2 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * tlen);
	fftw_plan p_2 = fftw_plan_dft_r2c_1d(tlen, in_2, out_2, FFTW_ESTIMATE);

    double* in_3 = (double*) fftw_malloc(sizeof(double) * tlen);
    fftw_complex* out_3 = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * tlen);
	fftw_plan p_3 = fftw_plan_dft_r2c_1d(tlen, in_3, out_3, FFTW_ESTIMATE);
    
    for (int n = 0; n < tlen; ++n) {
        in_1[n] = y_k1_2D[n][5];
        in_2[n] = y_k2_2D[n][5];
        in_3[n] = in_1[n] + in_2[n];
    }

    fftw_execute(p_1);
    fftw_execute(p_2);
    fftw_execute(p_3);

    double freq;
    double time;
    for (int n = 0; n < tlen; ++n) {
        freq = n/(tlen*dt);
        time = n*dt;
        fprintf(fft_k1, "t: %lf a: %lf f: %lf re: %lf im %lf\n", time, in_1[n], freq, out_1[n][0], out_1[n][1]);
        fprintf(fft_k2, "t: %lf a: %lf f: %lf re: %lf im %lf\n", time, in_2[n], freq, out_2[n][0], out_2[n][1]);
        fprintf(fft_add_k12, "t: %lf a: %lf f: %lf re: %lf im %lf\n", time, in_3[n], freq, out_3[n][0], out_3[n][1]);
    }

    
    fclose(prop_k1);
    fclose(prop_k2);
    fclose(add_k12);
    fclose(prop_k12);
    fclose(fft_k1);
    fclose(fft_k2);
    fclose(fft_add_k12);
    fftw_destroy_plan(p_1);
	fftw_free(in_1);
	fftw_free(out_1);
    fftw_destroy_plan(p_2);
	fftw_free(in_2);
	fftw_free(out_2);
    fftw_destroy_plan(p_3);
	fftw_free(in_3);
	fftw_free(out_3);
    arr_2D_destroyer(y_k1_2D, tlen);
    arr_2D_destroyer(y_k2_2D, tlen);
    arr_2D_destroyer(y_k12_2D, tlen);
    return 0;
}
