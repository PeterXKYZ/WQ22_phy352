#!/usr/bin/bash

for FILE in $(ls src/)
    do
        gcc -std=c99 -O2 -I include/ -I ../include/ -I /software/gsl/2.6-gcc-8.4.0/include/ \
        src/$FILE -c -o object/$(echo $FILE | sed 's/c$/o/') \
        -lm -L/software/gsl/2.6-gcc-8.4.0/lib -l gsl -l gslcblas
        # sed 's/c$/o' explaination
        # c$ finds the ending c and replaces it with o
        # https://www.geeksforgeeks.org/how-to-use-regular-expressions-regex-on-linux/
done

ar -r lib/libphysics.a object/*