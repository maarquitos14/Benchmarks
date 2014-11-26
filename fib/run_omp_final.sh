#!/bin/bash

#BSUB -n 1
#BSUB -J fib_omp 
#BSUB -oo fib_omp.out
#BSUB -eo fib_omp.err
#BSUB -W 00:10

#for i in {18..22}
for i in {43..47}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 18
		then
			NX_ARGS="--summary --smp-workers=1" ./fib_omp $i 1
		else
			NX_ARGS="--summary --smp-workers=1" ./fib_omp $i 2
		fi	
	done
done

