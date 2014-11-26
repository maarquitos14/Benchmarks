#!/bin/bash

#BSUB -n 1
#BSUB -J mpc_omp_memo 
#BSUB -oo mpc_omp_memo.out
#BSUB -eo mpc_omp_memo.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 29
		then
			NX_ARGS="--summary --smp-workers=1" ./mpc_omp_memo $i 8
		elif test $i -le 31
		then
			NX_ARGS="--summary --smp-workers=1" ./mpc_omp_memo $i 9
		else
			NX_ARGS="--summary --smp-workers=1" ./mpc_omp_memo $i 10 
		fi	
	done
done

