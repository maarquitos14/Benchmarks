#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo fib.out
#BSUB -eo fib.err
#BSUB -J fib 
#BSUB -x
#BSUB -W 00:30

rm outputs_yield outputs_no_yield

#for i in {72..76}
for i in 76
do
    echo "Problem size $i" >> outputs_yield
    echo "Problem size $i" >> outputs_no_yield
    for j in {1..5}
    do
        NX_ARGS="--summary" ./fib_omp_memo_yield $i 33 2>> outputs_yield 1>> outputs_yield
        NX_ARGS="--summary" ./fib_omp_memo_no_yield $i 33 2>> outputs_no_yield 1>> outputs_no_yield
    done
done    
