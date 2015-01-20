#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo car_overhead.out
#BSUB -eo car_overhead.err
#BSUB -J car_overhead 
#BSUB -x
#BSUB -W 00:30

#rm outputs_serial outputs_memo outputs_omp outputs_omp_memo
rm outputs_omp_memo

for i in {28..32}
do
#    echo "Problem size $i" >> outputs_serial 
#    echo "Problem size $i" >> outputs_memo 
#    echo "Problem size $i" >> outputs_omp
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-15
#        ./car input-50.txt $i 2>> outputs_serial 1>> outputs_serial
#        ./car_memo input-50.txt $i 2>> outputs_memo 1>> outputs_memo
#        NX_ARGS="--smp-workers=1" ./car_omp input-50.txt $i 8 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=1" ./car_omp_memo input-50.txt $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
