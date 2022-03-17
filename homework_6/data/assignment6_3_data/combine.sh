#!/usr/bin/bash

for FILE in `ls slurm_out_20/ | sort -t '_' -k3 -n`; do
    cat slurm_out_20/$FILE >> C-T_20.dat
done

for FILE in `ls slurm_out_50/ | sort -t '_' -k3 -n`; do
    cat slurm_out_50/$FILE >> C-T_50.dat
done

for FILE in `ls slurm_out_100/ | sort -t '_' -k3 -n`; do
    cat slurm_out_100/$FILE >> C-T_100.dat
done