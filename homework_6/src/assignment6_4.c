#include <stdio.h>
#include <stdlib.h>
#include <IsingLattice2D.h>
#include <magnetism.h>

#define NSWEEPS 50000

int main(int argc, char** argv) {

    if (argc != 4) {
        printf("Usage: <#RANDOM> <temperature T> <magnetic field H>");
        return 1;
    }

    unsigned seed = strtoul(argv[1], NULL, 10); 
    srand(seed);
    double T = strtod(argv[2], NULL);
    double H = strtod(argv[3], NULL);
    const size_t N = 100;

    IsingLattice2D* lattice = create2DIsingLattice( N, N, T, H );
    CorrelationInfo info;
    info.spinsums = (double*) (calloc(N, sizeof(double)));
    info.spinprodsums = (double*) (calloc(N, sizeof(double)));
    info.tests = 0;

    // warm up if not wanting timeseries data ...
    for( size_t i = 0; i < 1000; ++i ) { 
        sweep( lattice, boltzmannFlip );
    }

    for (size_t i = 0; i < NSWEEPS; ++i) {
        sweep( lattice, boltzmannFlip );
        getCorrelationInfo(lattice, &info);
    }


    for (size_t i = 1; i < N/2; ++i) {
        double f_minus_avgS2 = (info.spinprodsums[i])/info.tests
        - (info.spinsums[0]/info.tests)*(info.spinsums[0]/info.tests);
        printf("i: %d\tcorr_func: %f\n", i, f_minus_avgS2);
    }

    return 0;
}
