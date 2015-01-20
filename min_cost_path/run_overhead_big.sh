#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo mcp_overhead_big.out
#BSUB -eo mcp_overhead_big.err
#BSUB -J mcp_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 199 299 399 499 599 
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-6
        let size=$i+1
#        ./mcp_memo input-1000x1000.txt 1000 $size 999 $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./mcp_omp_memo input-1000x1000.txt 1000 $size 999 $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
