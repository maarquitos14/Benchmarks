#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo knapsack.out
#BSUB -eo knapsack.err
#BSUB -J knapsack 
#BSUB -x
#BSUB -W 00:30

rm outputs_yield outputs_no_yield

#for i in {46..50}
for i in 50
do
    echo "Problem size $i" >> outputs_yield
    echo "Problem size $i" >> outputs_no_yield
    for j in {1..5}
    do
        NX_ARGS="--summary" ./knapsack_omp_memo_yield input-64.txt $i 20 2>> outputs_yield 1>> outputs_yield
        NX_ARGS="--summary" ./knapsack_omp_memo_no_yield input-64.txt $i 20 2>> outputs_no_yield 1>> outputs_no_yield
    done
done    
