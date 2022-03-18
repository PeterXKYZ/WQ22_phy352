#!/usr/bin/bash

./bin/assignment6_5.exe $RANDOM `echo ".95 * 2.3" | bc -l` 0 100 1000 | grep -v -e "making" -e "done" > \
data/assignment6_5_data/snap_1000.dat 

./bin/assignment6_5.exe $RANDOM `echo ".95 * 2.3" | bc -l` 0 100 5000 | grep -v -e "making" -e "done" > \
data/assignment6_5_data/snap_5000.dat 

./bin/assignment6_5.exe $RANDOM `echo ".95 * 2.3" | bc -l` 0 100 10000 | grep -v -e "making" -e "done" > \
data/assignment6_5_data/snap_10000.dat 

./bin/assignment6_5.exe $RANDOM `echo ".95 * 2.3" | bc -l` 0 100 50000 | grep -v -e "making" -e "done" > \
data/assignment6_5_data/snap_50000.dat 

