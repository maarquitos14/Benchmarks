#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo fib_weak_scaling.out
#BSUB -eo fib_weak_scaling.err
#BSUB -J fib_weak_scaling 
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
                let size=40
                ;;
            2)
                let size=42
                ;;
            4)
#                let size=43
                let size=44
                ;;
            8)
                let size=45
                ;;
            16)
#                let size=47
                let size=46
                ;;
        esac
        let aux=$size-15
        ./fib $size 2>> outputs_serial 1>> outputs_serial
        ./fib_memo $size 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./fib_omp $size 10 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./fib_omp_memo $size $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
