#!/usr/bin/bash

rm data/C-T.dat

i=1;
while ((`echo "$i < 5.1" | bc -l`))
    do
        ./bin/assignment6_3.exe $RANDOM $i 0 10 | grep "T:" >> ./data/C-T.dat
        i=`echo "$i + 0.1" | bc -l`
done
