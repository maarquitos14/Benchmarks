#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo lis_weak_scaling.out
#BSUB -eo lis_weak_scaling.err
#BSUB -J lis_weak_scaling 
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
                let size=150
                let aux1=$size-155
                ;;
            2)
                let size=165
                let aux1=$size-155
                ;;
            4)
                let size=175
                let aux1=$size-155
                ;;
            8)
                let size=210
                let aux1=$size-155
                ;;
            16)
                let size=245
                let aux1=60
                ;;
        esac
        let aux0=$size-85
        ./lis input-2000.txt $size 2>> outputs_serial 1>> outputs_serial
        ./lis_memo input-2000.txt $size 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./lis_omp input-2000.txt $size $aux1 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./lis_omp_memo input-2000.txt $size $aux0 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
