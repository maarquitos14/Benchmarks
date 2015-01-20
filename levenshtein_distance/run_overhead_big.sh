#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo levenshtein_distance_overhead_big.out
#BSUB -eo levenshtein_distance_overhead_big.err
#BSUB -J levenshtein_distance_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 450 562 675 788 800 
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-1
#        ./levenshtein_distance_memo input-$i.txt 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./levenshtein_distance_omp_memo input-$i.txt $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
