#!/bin/bash

#SBATCH -A e20271               # Allocation
#SBATCH -p short                # Queue
#SBATCH -t 04:00:00             # Walltime/duration of the job
#SBATCH -N 1                    # Number of Nodes
#SBATCH --mem=18G               # Memory per node in GB needed for a job. Also see --mem-per-cpu
#SBATCH --ntasks-per-node=6     # Number of Cores (Processors)
#SBATCH --output=./slurm/logs/%A_%a.out   # Path for output must already exist
#SBATCH --error=./slurm/logs/%A_%a.err    # Path for errors must already exist
#SBATCH --job-name="assignment6_2"  # Name of job
#SBATCH --array 0-179            # Job array 

id=${SLURM_ARRAY_TASK_ID}

if [ $id -lt 60 ]
then 
    N=20
    path="./data/assignment6_3_data/slurm_out_20"
elif [ $id -ge 60 ] && [ $id -lt 120 ]
then 
    N=50
    id=$(($id-60))
    path="./data/assignment6_3_data/slurm_out_50"
else
    N=100
    id=$(($id-120))
    path="./data/assignment6_3_data/slurm_out_100"
fi

T=`echo "1 + ($id * .05)" | bc -l`
./bin/assignment6_2.exe $RANDOM $T 0 $N | grep "T:" >> $path/C-T_${N}_${id}_.dat

