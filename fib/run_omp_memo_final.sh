#!/bin/bash

#BSUB -n 1
#BSUB -J fib_omp_memo 
#BSUB -oo fib_omp_memo.out
#BSUB -eo fib_omp_memo.err
#BSUB -W 00:10

#for i in {18..22}
for i in {43..47}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 18 || test $i -eq 19
		then
			NX_ARGS="--summary --smp-workers=1" ./fib_omp_memo $i 5
		else
			NX_ARGS="--summary --smp-workers=1" ./fib_omp_memo $i 6
		fi	
	done
done

