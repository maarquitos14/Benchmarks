#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo knapsack_strong_scaling_big.out
#BSUB -eo knapsack_strong_scaling_big.err
#BSUB -J knapsack_strong_scaling_big 
#BSUB -x
#BSUB -W 00:30

rm outputs_omp_memo

for i in 1 2 4 8 16 
do
    echo "Number of threads $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=2800-75
        NX_ARGS="--smp-workers=$i" ./knapsack_omp_memo input-1000000.txt 2800 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
