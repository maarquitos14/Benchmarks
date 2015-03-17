#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo fib_strong_scaling_big.out
#BSUB -eo fib_strong_scaling_big.err
#BSUB -J fib_strong_scaling_big 
#BSUB -x
#BSUB -W 00:30

rm outputs_omp_memo

#for i in 1 2 4 8 16 
for i in 2
do
    echo "Number of threads $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=1000000-15
        NX_ARGS="--smp-workers=$i" ./fib_omp_memo 1000000 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
