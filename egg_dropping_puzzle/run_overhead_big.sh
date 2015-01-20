#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo edp_overhead_big.out
#BSUB -eo edp_overhead_big.err
#BSUB -J edp_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 250 300 350 400 450 
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-12
#        ./edp_memo 10 $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./edp_omp_memo 10 $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
