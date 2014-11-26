#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo edp_strong_scaling.out
#BSUB -eo edp_strong_scaling.err
#BSUB -J edp_strong_scaling 
#BSUB -x
#BSUB -W 00:20

echo "edp_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./edp_omp 10 21 4
	done
done

echo "edp_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./edp_omp_memo 10 21 6
	done
done
