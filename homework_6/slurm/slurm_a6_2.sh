#!/bin/bash

#SBATCH -A e20271               # Allocation
#SBATCH -p short                # Queue
#SBATCH -t 04:00:00             # Walltime/duration of the job
#SBATCH -N 1                    # Number of Nodes
#SBATCH --mem=18G               # Memory per node in GB needed for a job. Also see --mem-per-cpu
#SBATCH --ntasks-per-node=6     # Number of Cores (Processors)
#SBATCH --output=./slurm/logs/%A_%a.out   # Path for output must already exist
#SBATCH --error=./slurm/logs/%A_%a.err    # Path for errors must already exist
#SBATCH --job-name="circleInt"  # Name of job
#SBATCH --array 0-19            # Job array 

id=${SLURM_ARRAY_TASK_ID}

rm ./slurm/output/*

i=`echo ".5 + $id" | bc -l`
lim=`echo "$i + 1" | bc - l`
while ((`echo "$i < $lim" | bc -l`))
    do
        ./bin/assignment6_2.exe $RANDOM $i 0 | grep "T:" >> ./slurm/output/E-T_$id.dat
        i=`echo "$i + 0.1" | bc -l`
done
