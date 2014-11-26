#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo car_strong_scaling.out
#BSUB -eo car_strong_scaling.err
#BSUB -J car_strong_scaling 
#BSUB -x
#BSUB -W 00:20

echo "car_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./car_omp input-50.txt 32 8
	done
done

echo "car_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./car_omp_memo input-50.txt 32 11
	done
done
