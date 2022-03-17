#include <stdio.h>
#include <stdlib.h>
#include <IsingLattice2D.h>
#include <magnetism.h>

#define NSWEEPS 10000

int main(int argc, char** argv) {

    if (argc != 5) {
        printf("Usage: <#RANDOM> <temperature T> <magnetic field H> <lattice size>");
        return 1;
    }

    unsigned seed = strtoul(argv[1], NULL, 10); 
    srand(seed);
    double T = strtod(argv[2], NULL);
    double H = strtod(argv[3], NULL);
    int N = atoi(argv[4]);

    IsingLattice2D* lattice = create2DIsingLattice( N, N, T, H );

    // warm up if not wanting timeseries data ...
    for( size_t i = 0; i < 1000; ++i ) { 
        sweep( lattice, boltzmannFlip );
    }

    double E = 0;
    double E_sum = 0;
    double E_squared_sum = 0;
    
    for( size_t i = 0; i < NSWEEPS; ++i ) { 
        sweep( lattice, boltzmannFlip );
        E = getEnergy(lattice);
        E_sum += E;
        E_squared_sum += E * E;
    }

    double variance = (E_squared_sum - (E_sum * E_sum / NSWEEPS) ) / (N * N * NSWEEPS);
    double C = variance / (kB * T * T);

    printf( "T: %lf\tC: %lf\n", T, C );

    return 0;
}
