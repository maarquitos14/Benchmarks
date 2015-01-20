#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mpc_weak_scaling.out
#BSUB -eo mpc_weak_scaling.err
#BSUB -J mpc_weak_scaling 
#BSUB -x
#BSUB -W 00:30

rm outputs_serial outputs_memo outputs_omp_memo outputs_omp

for i in 1 2 4 8 16 
do
    echo "Number of threads $i" >> outputs_serial
    echo "Number of threads $i" >> outputs_memo
    echo "Number of threads $i" >> outputs_omp
    echo "Number of threads $i" >> outputs_omp_memo
    for j in {1..5}
    do
        case $i in 
            1)
                let size=28
                ;;
            2)
                let size=29
                ;;
            4)
                let size=30
                ;;
            8)
                let size=31
                ;;
            16)
                let size=32
                ;;
        esac
        let aux=$size-18
        ./mpc $size 2>> outputs_serial 1>> outputs_serial
        ./mpc_memo $size 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./mpc_omp $size 7 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./mpc_omp_memo $size $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
