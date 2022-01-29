#!/bin/sh

# apparently you need to use -lm to link to the math library (which is dumb)
gcc -std=c99 -I ode/include/ -I physics/include/ src/assignment3_2.c -o bin/assignment3_2 -L ode/lib/ -l ode -lm physics/object/assignment3_2_physics.o

gcc -std=c99 -I ode/include/ -I physics/include/ src/assignment3_3.c -o bin/assignment3_3 -L ode/lib/ -l ode -lm physics/object/assignment3_3_physics.o

./run/run_assignment3_2.sh
./run/run_assignment3_3.sh
