#!/usr/bin/bash


gcc -std=c99 -O2 -I Ising/include/ -I IsingPhysics/include/ src/assignment6_4.c -o bin/assignment6_4.exe \
-L Ising/lib/ -l Ising -L IsingPhysics/lib/ -l IsingPhysics2 -lm

