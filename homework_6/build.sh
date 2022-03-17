#!/usr/bin/bash

rm bin/*

for FILE in $(ls src/)
    do
        gcc -std=c99 -O2 -I Ising/include/ -I IsingPhysics/include/ src/$FILE -o bin/$(echo $FILE | sed 's/c$/exe/') \
        -L Ising/lib/ -l Ising -L IsingPhysics/lib/ -l IsingPhysics -lm 
done

