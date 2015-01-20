#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mpc_strong_scaling.out
#BSUB -eo mpc_strong_scaling.err
#BSUB -J mpc_strong_scaling 
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
        let aux=32-18
#        NX_ARGS="--smp-workers=$i" ./mpc_omp 32 7 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./mpc_omp_memo 32 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
