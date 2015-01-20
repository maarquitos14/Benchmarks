#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo lis_overhead_big.out
#BSUB -eo lis_overhead_big.err
#BSUB -J lis_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_memo outputs_omp_memo

for i in 850 1025 1200 1375 1550 
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-85
#        ./lis_memo input-2000.txt $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./lis_omp_memo input-2000.txt $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
