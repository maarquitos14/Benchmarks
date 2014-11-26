#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo bst_strong_scaling.out
#BSUB -eo bst_strong_scaling.err
#BSUB -J bst_strong_scaling 
#BSUB -x
#BSUB -W 00:20

echo "bst_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./bst_omp 21 6
	done
done

echo "bst_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./bst_omp_memo 21 7
	done
done
