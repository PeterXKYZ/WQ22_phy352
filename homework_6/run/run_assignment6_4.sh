#!/usr/bin/bash

./bin/assignment6_4.exe $RANDOM `echo ".5 * 2.3" | bc -l` 0 | grep "i:" > data/assignment6_4_data/corr_.5_.dat

./bin/assignment6_4.exe $RANDOM `echo ".95 * 2.3" | bc -l` 0 | grep "i:" > data/assignment6_4_data/corr_.95_.dat

./bin/assignment6_4.exe $RANDOM `echo "2 * 2.3" | bc -l` 0 | grep "i:" > data/assignment6_4_data/corr_2_.dat

