#!/usr/bin/bash

rm bin/*

gcc -std=c99 -I physics/include/ -I solver/include/ src/midterm_1_main.c -o bin/midterm_1_main_unopt \
    -L solver/lib -l solver_unopt -L physics/lib -l physics_unopt -lm

gcc -std=c99 -O2 -I physics/include/ -I solver/include/ src/midterm_1_main.c -o bin/midterm_1_main_opt \
    -L solver/lib -l solver_opt -L physics/lib -l physics_opt -lm