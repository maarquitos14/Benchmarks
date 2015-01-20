#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo mpc_overhead_big.out
#BSUB -eo mpc_overhead_big.err
#BSUB -J mpc_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 1100 1325 1550 1775 2000 
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-18
#        ./mpc_memo $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./mpc_omp_memo $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
