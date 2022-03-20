#!/usr/bin/bash

if [ ! -d bin/ ]
then
    mkdir bin
fi

gcc -std=c99 -O2 -I Ising/include/ -I Neural/include/ src/main.c -o bin/main.exe \
-L Ising/lib/ -l Ising -L Neural/lib/ -l Neural -lm