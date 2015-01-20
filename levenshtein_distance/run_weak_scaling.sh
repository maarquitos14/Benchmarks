#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo levenshtein_distance_weak_scaling.out
#BSUB -eo levenshtein_distance_weak_scaling.err
#BSUB -J levenshtein_distance_weak_scaling 
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
                size=11x13
                let big_dim=13
                ;;
            2)
                size=11x14
                let big_dim=14
                ;;
            4)
                size=11x15
                let big_dim=15
                ;;
            8)
                size=11x16
                let big_dim=16
                ;;
            16)
                size=11x17
                let big_dim=17
                ;;
        esac
        let aux=$big_dim-6
        ./levenshtein_distance input-$size.txt 2>> outputs_serial 1>> outputs_serial
        ./levenshtein_distance_memo input-$size.txt 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./levenshtein_distance_omp input-$size.txt 5 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./levenshtein_distance_omp_memo input-$size.txt $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
