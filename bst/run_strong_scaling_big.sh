#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo bst_strong_scaling_big.out
#BSUB -eo bst_strong_scaling_big.err
#BSUB -J bst_strong_scaling_big 
#BSUB -x
#BSUB -W 00:30

rm outputs_omp_memo

for i in 1 2 4 8 16 
do
    echo "Number of threads $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=1800-10
        NX_ARGS="--smp-workers=$i" ./bst_omp_memo 1800 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
