#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo car_weak_scaling.out
#BSUB -eo car_weak_scaling.err
#BSUB -J car_weak_scaling 
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
        let aux=$size-15
        ./car input-50.txt $size 2>> outputs_serial 1>> outputs_serial
        ./car_memo input-50.txt $size 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./car_omp input-50.txt $size 8 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./car_omp_memo input-50.txt $size $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
