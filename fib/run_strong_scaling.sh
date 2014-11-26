#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo fib_strong_scaling.out
#BSUB -eo fib_strong_scaling.err
#BSUB -J fib_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "fib_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./fib_omp 47 13
	done
done

echo "fib_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./fib_omp_memo 47 14
	done
done
