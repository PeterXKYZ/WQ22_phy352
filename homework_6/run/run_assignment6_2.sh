#!/usr/bin/bash

rm data/E-T.dat

i=0.5;
while ((`echo "$i < 20.0" | bc -l`))
    do
        ./bin/assignment6_2.exe $RANDOM $i 0 | grep "T:">> ./data/E-T.dat
        i=`echo "$i + 0.1" | bc -l`
done