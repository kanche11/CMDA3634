#!/bin/bash
#PBS -l walltime=01:00:00
#PBS -l nodes=1:ppn=20
#PBS -W group_list=newriver
#PBS -q normal_q
#PBS -A CMDA3634
#Change to the directory from which the job was submitted
cd $PBS_O_WORKDIR
#Load modules
module purge; module load gcc mvapich2
#May not be necessary if the program is already built
gcc -O3 -fopenmp -o mandelbrot mandelbrot.c -lm
#Run
echo "Run Mandelbrot with $PBS_NP cores"
for i in {1..20};
do
./mandelbrot 4096 4096 $i
done
exit;
