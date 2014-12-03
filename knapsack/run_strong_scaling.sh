#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo knapsack_strong_scaling.out
#BSUB -eo knapsack_strong_scaling.err
#BSUB -J knapsack_strong_scaling 
#BSUB -x
#BSUB -W 00:30

rm outputs_serial outputs_memo outputs_omp_memo outputs_omp

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
        if test $i -eq 1
        then
            ./knapsack input-64.txt 36 2>> outputs_serial 1>> outputs_serial
            ./knapsack_memo input-64.txt 36 2>> outputs_memo 1>> outputs_memo
        fi
        NX_ARGS="--summary --smp-workers=$i" ./knapsack_omp_memo input-64.txt 36 16 2>> outputs_omp_memo 1>> outputs_omp_memo
        NX_ARGS="--summary --smp-workers=$i" ./knapsack_omp input-64.txt 36 9 2>> outputs_omp 1>> outputs_omp
	done
done
