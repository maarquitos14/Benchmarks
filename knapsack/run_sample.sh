#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo knapsack_sample.out
#BSUB -eo knapsack_sample.err
#BSUB -J knapsack_sample 
#BSUB -x
#BSUB -W 00:30

rm outputs_omp_memo outputs_memo

for i in 1 2 3 4 5
do
    ./knapsack_memo input-1000000.txt 10459  2>> outputs_memo 1>> outputs_memo
#    for j in 10000 12500 15000 17500 20000 
#    for j in 10459
    for j in 1 2 4 8 16 
    do
        echo "Number of threads $j" >> outputs_omp_memo
        NX_ARGS="--stack-size=20000000 --smp-workers=$j" ./knapsack_omp_memo_final input-1000000.txt 10459 4 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
