#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo lcs_weak_scaling.out
#BSUB -eo lcs_weak_scaling.err
#BSUB -J lcs_weak_scaling 
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
                size=11x23
                let big_dim=23
                ;;
            2)
                size=10x30
                let big_dim=30
                ;;
            4)
                size=8x45
                let big_dim=45
                ;;
            8)
                size=11x29
                let big_dim=29
                ;;
            16)
                size=13x24
                let big_dim=24
                ;;
        esac
        let aux=$big_dim-8
        ./lcs input-$size.txt 2>> outputs_serial 1>> outputs_serial
        ./lcs_memo input-$size.txt 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./lcs_omp input-$size.txt 5 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./lcs_omp_memo input-$size.txt $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
