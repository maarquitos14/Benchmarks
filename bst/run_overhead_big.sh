#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo bst_overhead_big.out
#BSUB -eo bst_overhead_big.err
#BSUB -J bst_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 1000 1200 1400 1600 1800
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-10
#        ./bst_memo $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./bst_omp_memo $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
