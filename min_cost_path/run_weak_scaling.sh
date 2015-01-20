#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mcp_weak_scaling.out
#BSUB -eo mcp_weak_scaling.err
#BSUB -J mcp_weak_scaling 
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
                let x=9
                let y=14
                ;;
            2)
                let x=6
                let y=28
                ;;
            4)
                let x=11
                let y=13
                ;;
            8)
                let x=8
                let y=21
                ;;
            16)
                let x=11
                let y=15
                ;;
        esac
        let dim0=x+1
        let dim1=y+1
        let aux=y-6
        ./mcp input-50x50.txt $dim0 $dim1 $x $y 2>> outputs_serial 1>> outputs_serial
        ./mcp_memo input-50x50.txt $dim0 $dim1 $x $y 2>> outputs_memo 1>> outputs_memo
        NX_ARGS="--smp-workers=$i" ./mcp_omp input-50x50.txt $dim0 $dim1 $x $y 5 2>> outputs_omp 1>> outputs_omp
        NX_ARGS="--smp-workers=$i" ./mcp_omp_memo input-50x50.txt $dim0 $dim1 $x $y $aux 2>> outputs_omp_memo 1>> outputs_omp_memo
	done
done
