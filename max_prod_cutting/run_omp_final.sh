#!/bin/bash

#BSUB -n 1
#BSUB -J mpc_omp 
#BSUB -oo mpc_omp.out
#BSUB -eo mpc_omp.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 30
		then
			NX_ARGS="--summary --smp-workers=1" ./mpc_omp $i 6
		elif test $i -eq 31
		then
			NX_ARGS="--summary --smp-workers=1" ./mpc_omp $i 7
		else
			NX_ARGS="--summary --smp-workers=1" ./mpc_omp $i 8
		fi	
	done
done

