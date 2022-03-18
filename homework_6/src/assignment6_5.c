#include <stdio.h>
#include <stdlib.h>
#include <IsingLattice2D.h>
#include <magnetism.h>

#define NSWEEPS 10000

int main(int argc, char** argv) {

    if (argc != 6) {
        printf("Usage: <#RANDOM> <temperature T> <magnetic field H> <lattice size> <sweeps>");
        return 1;
    }

    unsigned seed = strtoul(argv[1], NULL, 10); 
    srand(seed);
    double T = strtod(argv[2], NULL);
    double H = strtod(argv[3], NULL);
    int N = atoi(argv[4]);
    int SW = atoi(argv[5]);

    IsingLattice2D* lattice = create2DIsingLattice( N, N, T, H );

    for (size_t i = 0; i < SW; ++i) {
        sweep( lattice, boltzmannFlip );
    }

    myDump(lattice);

    return 0;
}
