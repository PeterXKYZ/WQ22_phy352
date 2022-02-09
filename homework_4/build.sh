#!/bin/sh

gcc -std=c99 -I physics/include/ src/assignment4_1.c -o bin/assignment4_1 -L physics/lib/ -l wave -lm
gcc -std=c99 -I physics/include/ src/assignment4_2.c -o bin/assignment4_2 -L physics/lib/ -l wave -lm -lfftw3
