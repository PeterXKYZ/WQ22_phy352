#include <stdio.h>
#include <stdlib.h>
#include <IsingLattice2D.h>
#include <magnetism.h>

#define NSWEEPS 10000

int main(int argc, char** argv) {

    if (argc != 4) {
        printf("Usage: <#RANDOM> <temperature T> <magnetic field H>");
        return 1;
    }

    unsigned seed = strtoul(argv[1], NULL, 10); 
    srand(seed);
    double T = strtod(argv[2], NULL);
    double H = strtod(argv[3], NULL);

    IsingLattice2D* lattice = create2DIsingLattice( 10, 10, T, H );

    // warm up if not wanting timeseries data ...
    for( size_t i = 0; i < 1000; ++i ) { 
        sweep( lattice, boltzmannFlip );
    }

    double E_N = 0;
    for( size_t i = 0; i < NSWEEPS; ++i ) { 
        sweep( lattice, boltzmannFlip );
        E_N += getEnergyPerSpin(lattice);
    }
    E_N /= NSWEEPS;

    printf( "T: %lf\tM: %lf\n", T, E_N );

    return 0;
}