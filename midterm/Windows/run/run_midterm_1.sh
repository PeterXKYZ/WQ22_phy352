#!/usr/bin/bash

tsteps="0.05 0.01 0.005 0.001 0.0005 0.0001"
method="euler rkO2 rkO4"

path="data/midterm_1_data/unopt/"

rm ${path}*

for t in $tsteps; do 
    for m in $method; do
        ./bin/midterm_1_main.exe $m $t yes >> ${path}combined.dat
        perf stat ./bin/midterm_1_main.exe $m $t >& ${path}temp
        ninst=`grep instru ${path}temp  | awk '{print $1}' | sed -e 's/,//g'`
        echo instructions: $ninst >> ${path}combined.dat
    done   
    printf "\n" >> ${path}combined.dat 
done

rm ${path}temp

# paste -d " " ${path}euler.dat ${path}euler_perf.dat \
#            ${path}rkO2.dat ${path}rkO2_perf.dat \
#            ${path}rkO4.dat ${path}rkO4_perf.dat > ${path}combined.dat

