#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo lcs_strong_scaling.out
#BSUB -eo lcs_strong_scaling.err
#BSUB -J lcs_strong_scaling 
#BSUB -x
#BSUB -W 00:30

rm outputs_serial outputs_memo outputs_omp_memo outputs_omp

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
        if test $i -eq 1
        then
            ./lcs abcdefghijklmnopqr zyxwvutsrqponmlkji 2>> outputs_serial 1>> outputs_serial
            ./lcs_memo abcdefghijklmnopqr zyxwvutsrqponmlkji 2>> outputs_memo 1>> outputs_memo
        fi
		NX_ARGS="--summary --smp-workers=$i" ./lcs_omp_memo abcdefghijklmnopqr zyxwvutsrqponmlkji 11 2>> outputs_omp_memo 1>> outputs_omp_memo
		NX_ARGS="--summary --smp-workers=$i" ./lcs_omp abcdefghijklmnopqr zyxwvutsrqponmlkji 5 2>> outputs_omp 1>> outputs_omp
	done
done
