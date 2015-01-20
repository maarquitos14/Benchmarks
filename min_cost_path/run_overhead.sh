#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo mcp_overhead.out
#BSUB -eo mcp_overhead.err
#BSUB -J mcp_overhead 
#BSUB -x
#BSUB -W 00:30

#rm outputs_serial outputs_memo outputs_omp outputs_omp_memo
rm outputs_omp_memo

for i in {11..15}
do
#    echo "Problem size $i" >> outputs_serial 
#    echo "Problem size $i" >> outputs_memo 
#    echo "Problem size $i" >> outputs_omp
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-6
        let size=$i+1
#        ./mcp input-50x50.txt $size 12 $i 11 2>> outputs_serial 1>> outputs_serial
#        ./mcp_memo input-50x50.txt $size 12 $i 11 2>> outputs_memo 1>> outputs_memo
#        NX_ARGS="--smp-workers=1" ./mcp_omp input-50x50.txt $size 12 $i 11 5 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=1" ./mcp_omp_memo input-50x50.txt $size 12 $i 11 $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
