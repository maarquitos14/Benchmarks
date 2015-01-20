#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo lcs_overhead.out
#BSUB -eo lcs_overhead.err
#BSUB -J lcs_overhead 
#BSUB -x
#BSUB -W 00:30

#rm outputs_serial outputs_memo outputs_omp outputs_omp_memo
rm outputs_omp_memo

for i in {14..18}
do
#    echo "Problem size $i" >> outputs_serial 
#    echo "Problem size $i" >> outputs_memo 
#    echo "Problem size $i" >> outputs_omp
    echo "Problem size $i" >> outputs_omp_memo
    for j in {1..5}
    do
        let aux=$i-8
#        ./lcs input-$i.txt 2>> outputs_serial 1>> outputs_serial
#        ./lcs_memo input-$i.txt 2>> outputs_memo 1>> outputs_memo
#        NX_ARGS="--smp-workers=1" ./lcs_omp input-$i.txt 5 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=1" ./lcs_omp_memo input-$i.txt $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
