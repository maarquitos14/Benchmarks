#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo lis_overhead.out
#BSUB -eo lis_overhead.err
#BSUB -J lis_overhead 
#BSUB -x
#BSUB -W 00:30

#rm outputs_serial outputs_memo outputs_omp outputs_omp_memo
rm outputs_omp_memo

for i in 125 150 175 200 225
do
#    echo "Problem size $i" >> outputs_serial 
#    echo "Problem size $i" >> outputs_memo 
#    echo "Problem size $i" >> outputs_omp
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-85
#        ./lis input-2000.txt $i 2>> outputs_serial 1>> outputs_serial
#        ./lis_memo input-2000.txt $i 2>> outputs_memo 1>> outputs_memo
#        NX_ARGS="--smp-workers=1" ./lis_omp input-2000.txt $i 25 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=1" ./lis_omp_memo input-2000.txt $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
