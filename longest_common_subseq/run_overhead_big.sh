#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo lcs_overhead_big.out
#BSUB -eo lcs_overhead_big.err
#BSUB -J lcs_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 550 650 750 850 950 
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-2
#        ./lcs_memo input-$i.txt 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./lcs_omp_memo input-$i.txt $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
