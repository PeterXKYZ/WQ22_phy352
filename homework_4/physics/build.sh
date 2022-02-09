#!/bin/sh

# -lm links to the math library
gcc -std=c99 -I include/ src/constructors.c -c -o object/constructors.o

gcc -std=c99 -I include/ src/string_physics.c -c -o object/string_physics.o -lm

ar -r lib/libwave.a object/*