#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo knapsack_strong_scaling.out
#BSUB -eo knapsack_strong_scaling.err
#BSUB -J knapsack_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "knapsack_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./knapsack_omp input-64.txt 36 9
	done
done

echo "knapsack_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./knapsack_omp_memo input-64.txt 36 12
	done
done
