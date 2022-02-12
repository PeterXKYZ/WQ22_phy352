#!/usr/bin/bash

gcc -std=c99 -I physics/include/ -I solver/include/ src/midterm_1_main.c -o bin/midterm_1_main -L solver/lib -l solver_unopt -L physics/lib -l physics_unopt -lm