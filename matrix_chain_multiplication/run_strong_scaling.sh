#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mcm_strong_scaling.out
#BSUB -eo mcm_strong_scaling.err
#BSUB -J mcm_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "mcm_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./mcm_omp input-100.txt 22 3
	done
done

echo "mcm_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./mcm_omp_memo input-100.txt 22 5
	done
done
