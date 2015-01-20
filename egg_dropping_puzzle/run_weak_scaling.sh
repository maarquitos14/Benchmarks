#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo edp_weak_scaling.out
#BSUB -eo edp_weak_scaling.err
#BSUB -J edp_weak_scaling 
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
                let eggs=7
                let floors=19
                ;;
            2)
                let eggs=19
                let floors=19
                ;;
            4)
                let eggs=3
                let floors=26
                ;;
            8)
                let eggs=3
                let floors=27
                ;;
            16)
                let eggs=11
                let floors=21
                ;;
        esac
        let aux=$floors-12
        ./edp $eggs $floors 2>> outputs_serial 1>> outputs_serial
        ./edp_memo $eggs $floors 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./edp_omp $eggs $floors 5 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./edp_omp_memo $eggs $floors $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
