#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo mpc_overhead.out
#BSUB -eo mpc_overhead.err
#BSUB -J mpc_overhead 
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
        let aux=$i-18
#        ./mpc $i 2>> outputs_serial 1>> outputs_serial
#        ./mpc_memo $i 2>> outputs_memo 1>> outputs_memo
#        NX_ARGS="--smp-workers=1" ./mpc_omp $i 7 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=1" ./mpc_omp_memo $i $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
    done
done    
