#!/usr/bin/bash

for FILE in `ls slurm_out/ | sort -t '_' -k2 -n`; do
    cat slurm_out/$FILE >> E-T_combined.dat
done
