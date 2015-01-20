#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo knapsack_overhead_big.out
#BSUB -eo knapsack_overhead_big.err
#BSUB -J knapsack_overhead_big 
#BSUB -x
#BSUB -W 00:30

rm outputs_memo outputs_omp_memo
#rm outputs_omp_memo

for i in 600 1000 1600 2200 2800
do
    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-75
        ./knapsack_memo input-1000000.txt $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./knapsack_omp_memo input-1000000.txt $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
