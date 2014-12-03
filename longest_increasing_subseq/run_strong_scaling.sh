#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo lis_strong_scaling.out
#BSUB -eo lis_strong_scaling.err
#BSUB -J lis_strong_scaling 
#BSUB -x
#BSUB -W 00:30

rm outputs_omp_memo outputs_omp

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
        NX_ARGS="--summary --smp-workers=$i" ./lis_omp_memo input-200.txt 150 26 2>> outputs_omp_memo 1>> outputs_omp_memo
#NX_ARGS="--summary --smp-workers=$i" ./lis_omp input-200.txt 150 19 2>> outputs_omp 1>> outputs_omp
	done
done
