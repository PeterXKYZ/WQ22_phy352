#!/usr/bin/bash

testp="./mystery/001.dat"
inputp=$(ls ./character_groups/001/*.dat)
./bin/main.exe $RANDOM 0.0 0.0 $testp ${inputp[*]}


