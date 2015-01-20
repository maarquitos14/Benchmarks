#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo coin_change_weak_scaling.out
#BSUB -eo coin_change_weak_scaling.err
#BSUB -J coin_change_weak_scaling 
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
                let size=109
                ;;
            2)
                let size=120
                ;;
            4)
                let size=131
                ;;
            8)
                let size=142
                ;;
            16)
                let size=156
                ;;
        esac
        let aux=13
        ./coin_change input-10.txt 10 $size 2>> outputs_serial 1>> outputs_serial
        ./coin_change_memo input-10.txt 10 $size 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./coin_change_omp input-10.txt 10 $size 3 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./coin_change_omp_memo input-10.txt 10 $size $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
