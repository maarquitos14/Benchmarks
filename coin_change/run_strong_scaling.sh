#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo coin_change_strong_scaling.out
#BSUB -eo coin_change_strong_scaling.err
#BSUB -J coin_change_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "coin_change_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp input-10.txt 10 155 1
	done
done

echo "coin_change_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 155 3
	done
done
