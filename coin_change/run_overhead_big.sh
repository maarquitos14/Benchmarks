#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo coin_change_overhead_big.out
#BSUB -eo coin_change_overhead_big.err
#BSUB -J coin_change_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 30000 55000 80000 105000 130000
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=13
#        ./coin_change_memo input-10.txt 10 $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./coin_change_omp_memo input-10.txt 10 $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
