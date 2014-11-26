#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mpc_strong_scaling.out
#BSUB -eo mpc_strong_scaling.err
#BSUB -J mpc_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "mpc_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./mpc_omp 32 8
	done
done

echo "mpc_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./mpc_omp_memo 32 10
	done
done
