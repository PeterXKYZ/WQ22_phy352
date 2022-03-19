#include <stdio.h>

#include <IsingLattice2D.h>
#include <pattern.h>
#include <jmatrix.h>
#include <neural.h>

#define SWEEP_MAX 50
#define STRIP 1
#define SLEEP 1

int main(int argc, char** argv) {

    unsigned seed = strtoul(argv[1], NULL, 10);
    float randomization = strtof(argv[2], NULL);
    float damage = strtof(argv[3], NULL);
    
    // M = number of patterns
    // N = network size (N x N)
    int M = argc - 5;
    int N = 10;

    size_t i, j;
    
    // load input patterns into a jmatrix
    FILE** fsin = (FILE**) calloc(M, sizeof(FILE*));
    for (i = 0; i < M; ++i) {
        fsin[i] = fopen(argv[5+i], "r");
    }
    pattern* inputs = readPatterns(fsin, M, N);
    for (i = 0; i < M; ++i) {
        fclose(fsin[i]);
    }

    // Jmatrix creation
    Jmatrix* jmat = createJ(N, inputs, M);
    clear();
    for (i = 0; i < M; ++i) {
        printf("Loaded Network patterns, memory : %d\n\n", i);
        writePattern(&(inputs[i]), stdout, STRIP);
        sleep(SLEEP);
        clear();
    }

    // open the test pattern
    FILE** ftest = (FILE**) malloc(1*sizeof(FILE*));
    ftest[0] = fopen(argv[4], "r");
    pattern* test = readPatterns(ftest, 1, N);
    fclose(ftest[0]); //test pattern is loaded in by the ftest and test initialization

    clear();
    printf("pristine test pattern : \n\n");
    writePattern(test, stdout, STRIP);
    sleep(SLEEP);
    clear();


    // constuct a lattice using the test pattern and Jmatrix
    float T = 0;
    IsingLattice2D* lattice = create2DIsingLattice(N, N, T, 0);
    int sweeps = 0;
    IsingFromPattern(lattice, test, jmat);
    clear();


    // sweep until we settle into a minimum
    double prevenergy = 0;
    double currenergy = -5;
    double r;
    double hamming;
    pattern* out;

    while(prevenergy != currenergy && sweeps < SWEEP_MAX) {
        printf("sweep: %d\n\n", sweeps);
        out = PatternFromIsing(lattice);
        writePattern(out, stdout, STRIP);

        prevenergy = getTotalEnergy(lattice);

        sweep(lattice, &neuralFlip);

        currenergy = getTotalEnergy(lattice);
        if (currenergy != prevenergy) {
            sweeps++;
        }

        sleep(SLEEP);
        clear();
    }  

    printf("recalled: \n");
    out = PatternFromIsing(lattice);
    writePattern(out, stdout, STRIP);
    fflush(stdout);


    // compare against test patterns
    printf("\nChecking Hamming distances ...\n");
    int minIndex;
    double minHD=999;
    for( i = 0; i < M; ++i ) {
        double tmpHD = hammingDistance(out, &(inputs[i]));
        printf("index: %d\t pattern: %s\t hammingDistance: %f\n\n", i, argv[5+i], tmpHD);
        if( tmpHD < minHD ) { 
            minHD = tmpHD;
            minIndex = i;
        }
    }

    printf("nearest match: %d\thammingDistance: %f\n\n", minIndex, minHD);
    writePattern(&(inputs[minIndex]), stdout, STRIP);

    printf("\n");

    return minIndex;
}