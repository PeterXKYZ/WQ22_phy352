#!/usr/bin/bash

rm data/M-T.dat

i=0.5;
while ((`echo "$i < 5.0" | bc -l`))
    do
        ./bin/assignment6_1.exe $RANDOM $i 0 | grep "T:">> ./data/M-T.dat
        i=`echo "$i + 0.01" | bc -l`
done