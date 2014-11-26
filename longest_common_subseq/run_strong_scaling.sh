#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo lcs_strong_scaling.out
#BSUB -eo lcs_strong_scaling.err
#BSUB -J lcs_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "lcs_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./lcs_omp abcdefghijklmnopqr zyxwvutsrqponmlkji 5
	done
done

echo "lcs_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./lcs_omp_memo abcdefghijklmnopqr zyxwvutsrqponmlkji 6
	done
done
