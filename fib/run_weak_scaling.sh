#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo fib_weak_scaling.out
#BSUB -eo fib_weak_scaling.err
#BSUB -J fib_weak_scaling 
#BSUB -x
#BSUB -W 00:25

echo "fib_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp 47 13
		elif test $i -eq 2
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp 48 14
		elif test $i -eq 4
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp 50 14
		elif test $i -eq 8
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp 51 14
		else
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp 53 14
		fi
	done
done

echo "fib_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp_memo 47 14
		elif test $i -eq 2
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp_memo 49 15
		elif test $i -eq 4
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp_memo 50 16
		elif test $i -eq 8
		then
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp_memo 51 16
		else
			NX_ARGS="--summary --smp-workers=$i" ./fib_omp_memo 53 18
		fi
	done
done
