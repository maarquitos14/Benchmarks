#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo car_overhead_big.out
#BSUB -eo car_overhead_big.err
#BSUB -J car_overhead_big 
#BSUB -x
#BSUB -W 00:30

#rm outputs_memo outputs_omp_memo
rm outputs_omp_memo

for i in 1000 1250 1500 1750 2000 
do
#    echo "Problem size $i" >> outputs_memo 
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-15
#        ./car_memo input-5000.txt $i 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=1" ./car_omp_memo input-5000.txt $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
