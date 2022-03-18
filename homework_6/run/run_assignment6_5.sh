#!/usr/bin/bash

./bin/assignment6_5.exe $RANDOM `echo ".95 * 2.3" | bc -l` 0 100 10000 | grep -v -e "making" -e "done" > \
data/assignment6_5_data/test.dat 

