#!/usr/bin/bash

for FILE in $(ls src/)
    do
        gcc -std=c99  -I include/ src/$FILE -c -o object/opt/$(echo $FILE | sed 's/c$/o/')
        # sed 's/c$/o' explaination
        # c$ finds the ending c and replaces it with o
        # https://www.geeksforgeeks.org/how-to-use-regular-expressions-regex-on-linux/
done

gcc -std=c99 -O2 -I include/ src/constructors.c -c -o object/opt/constructors.o

ar -r lib/libsolver_opt.a object/opt/*
