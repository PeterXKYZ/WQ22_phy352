#!/usr/bin/bash

if [! -d "$object"]
then
    mkdir object
fi

if [! -d "$lib"]
then 
    mkdir lib
fi

for FILE in $(ls src/)
    do
        gcc -std=c99 -O2 -I include/ -I ../Ising/include/ src/$FILE -c -o object/$(echo $FILE | sed 's/c$/o/') -lm
        # sed 's/c$/o' explaination
        # c$ finds the ending c and replaces it with o
        # https://www.geeksforgeeks.org/how-to-use-regular-expressions-regex-on-linux/
done

ar -r lib/libIsingPhysics.a object/*