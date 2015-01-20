#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo edp_strong_scaling.out
#BSUB -eo edp_strong_scaling.err
#BSUB -J edp_strong_scaling 
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
        let aux=21-12
#        NX_ARGS="--smp-workers=$i" ./edp_omp 10 21 5 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./edp_omp_memo 10 21 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
