#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo car_strong_scaling.out
#BSUB -eo car_strong_scaling.err
#BSUB -J car_strong_scaling 
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
        let aux=32-15
#        NX_ARGS="--smp-workers=$i" ./car_omp input-50.txt 32 8 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./car_omp_memo input-50.txt 32 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
