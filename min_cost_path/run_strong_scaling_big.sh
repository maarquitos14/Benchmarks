#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mcp_strong_scaling_big.out
#BSUB -eo mcp_strong_scaling_big.err
#BSUB -J mcp_strong_scaling_big 
#BSUB -x
#BSUB -W 00:30

rm outputs_omp_memo

for i in 1 2 4 8 16 
do
    echo "Number of threads $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=599-6
        let size=599+1
        NX_ARGS="--smp-workers=$i" ./mcp_omp_memo input-1000x1000.txt 1000 $size 999 599 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
