#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo fib_strong_scaling.out
#BSUB -eo fib_strong_scaling.err
#BSUB -J fib_strong_scaling 
#BSUB -x
#BSUB -W 00:30

#rm outputs_omp_memo outputs_omp
rm outputs_omp_memo

for i in 1 2 4 8 16 
do
#    echo "Number of threads $i" >> outputs_omp
    echo "Number of threads $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=47-15
#        NX_ARGS="--smp-workers=$i" ./fib_omp 47 10 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./fib_omp_memo 47 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
