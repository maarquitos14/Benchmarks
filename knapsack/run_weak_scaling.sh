#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo knapsack_weak_scaling.out
#BSUB -eo knapsack_weak_scaling.err
#BSUB -J knapsack_weak_scaling 
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
                let size=104
                ;;
            2)
                let size=116
                ;;
            4)
                let size=133
                ;;
            8)
                let size=147
                ;;
            16)
                let size=148
                ;;
        esac
        let aux_memo=$size-75
        let aux_omp=$size-102
#        ./knapsack input-100000.txt $size 2>> outputs_serial 1>> outputs_serial
#        ./knapsack_memo input-100000.txt $size 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./knapsack_omp input-100000.txt $size $aux_omp 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./knapsack_omp_memo input-100000.txt $size $aux_memo 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
