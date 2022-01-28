#!/bin/sh

# ^ necessary to run, not a comment!
#chmod +x build.sh to make it executable
gcc -std=c99 -I include/ src/constructors.c -c -o object/constructors.o
gcc -std=c99 -I include/ src/rk_gen.c -c -o object/rk_gen.o
gcc -std=c99 -I include/ src/euler.c -c -o object/euler.o
gcc -std=c99 -I include/ src/rkO2.c -c -o object/rkO2.o
gcc -std=c99 -I include/ src/rkO4.c -c -o object/rkO4.o

ar -r lib/libode.a object/*
