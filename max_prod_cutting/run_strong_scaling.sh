#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mpc_strong_scaling.out
#BSUB -eo mpc_strong_scaling.err
#BSUB -J mpc_strong_scaling 
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
            ./mpc 32 2>> outputs_serial 1>> outputs_serial
            ./mpc_memo 32 2>> outputs_memo 1>> outputs_memo
        fi
        NX_ARGS="--summary --smp-workers=$i" ./mpc_omp_memo 32 10 2>> outputs_omp_memo 1>> outputs_omp_memo
        NX_ARGS="--summary --smp-workers=$i" ./mpc_omp 32 8 2>> outputs_omp 1>> outputs_omp
	done
done
