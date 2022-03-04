#!/usr/bin/bash

rm bin/*

gcc -std=c99 -O2 -I physics/include/ -I solver/include/ src/assignment5_1.c -o bin/assignment5_1.exe \
    -L solver/lib -l solver -L physics/lib -l physics -lm

gcc -std=c99 -O2 -I physics/include/ -I solver/include/ src/assignment5_2.c -o bin/assignment5_2.exe \
    -L solver/lib -l solver -L physics/lib -l physics -lm \
    -L/software/gsl/2.6-gcc-8.4.0/lib -lgsl -lgslcblas