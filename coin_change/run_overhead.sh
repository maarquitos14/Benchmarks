#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo coin_change_overhead.out
#BSUB -eo coin_change_overhead.err
#BSUB -J coin_change_overhead 
#BSUB -x
#BSUB -W 00:30

#rm outputs_serial outputs_memo outputs_omp outputs_omp_memo
rm outputs_omp_memo

for i in 115 125 135 145 155
do
#    echo "Problem size $i" >> outputs_serial 
#    echo "Problem size $i" >> outputs_memo 
#    echo "Problem size $i" >> outputs_omp
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=13
#        ./coin_change input-10.txt 10 $i 2>> outputs_serial 1>> outputs_serial
#        ./coin_change_memo input-10.txt 10 $i 2>> outputs_memo 1>> outputs_memo
#        NX_ARGS="--smp-workers=1" ./coin_change_omp input-10.txt 10 $i 3 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=1" ./coin_change_omp_memo input-10.txt 10 $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
