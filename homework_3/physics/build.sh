#!/bin/sh

# ^ needed to execute, not a comment!
# -lm links to the math library
gcc -std=c99 -I include/ src/assignment3_2_physics.c -c -o object/assignment3_2_physics.o

gcc -std=c99 -I include/ src/assignment3_3_physics.c -c -o object/assignment3_3_physics.o -lm

gcc -std=c99 -I include/ src/assignment3_4_physics.c -c -o object/assignment3_4_physics.o -lm
