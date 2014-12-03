#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mcm_strong_scaling.out
#BSUB -eo mcm_strong_scaling.err
#BSUB -J mcm_strong_scaling 
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
            ./mcm input-100.txt 22 2>> outputs_serial 1>> outputs_serial
            ./mcm_memo input-100.txt 22 2>> outputs_memo 1>> outputs_memo
        fi
        NX_ARGS="--summary --smp-workers=$i" ./mcm_omp_memo input-100.txt 22 5 2>> outputs_omp_memo 1>> outputs_omp_memo
        NX_ARGS="--summary --smp-workers=$i" ./mcm_omp input-100.txt 22 3 2>> outputs_omp 1>> outputs_omp
	done
done
