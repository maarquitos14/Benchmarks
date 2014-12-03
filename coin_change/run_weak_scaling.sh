#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo coin_change_weak_scaling.out
#BSUB -eo coin_change_weak_scaling.err
#BSUB -J coin_change_weak_scaling 
#BSUB -x
#BSUB -W 00:25

echo "coin_change_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp input-10.txt 10 155 1
		elif test $i -eq 2
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp input-10.txt 10 168 1
		elif test $i -eq 4
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp input-10.txt 10 182 1
		elif test $i -eq 8
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp input-10.txt 10 197 2
		else
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp input-10.txt 10 213 2
		fi
	done
done

echo "coin_change_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 155 3
		elif test $i -eq 2
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 168 3
		elif test $i -eq 4
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 182 3
		elif test $i -eq 8
		then
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 197 3
		else
			NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 213 3
		fi
	done
done