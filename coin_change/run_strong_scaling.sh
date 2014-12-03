#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo coin_change_strong_scaling.out
#BSUB -eo coin_change_strong_scaling.err
#BSUB -J coin_change_strong_scaling 
#BSUB -x
#BSUB -W 00:30

rm outputs_serial outputs_memo outputs_omp_memo outputs_omp

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
#if test $i -eq 1
#        then
#            ./coin_change input-10.txt 10 155 2>> outputs_serial 1>> outputs_serial
#            ./coin_change_memo input-10.txt 10 155 2>> outputs_memo 1>> outputs_memo
#        fi
#        NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 155 7 2>> outputs_omp_memo 1>> outputs_omp_memo
        NX_ARGS="--summary --smp-workers=$i" ./coin_change_omp input-10.txt 10 155 1 2>> outputs_omp 1>> outputs_omp
	done
done
