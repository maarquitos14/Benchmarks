#!/bin/bash

#BSUB -n 1
#BSUB -J knapsack_omp 
#BSUB -oo knapsack_omp.out
#BSUB -eo knapsack_omp.err
#BSUB -W 00:10

for i in {32..36}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 32 
		then
			NX_ARGS="--summary --smp-workers=1" ./knapsack_omp input-64.txt $i 8
		else
			NX_ARGS="--summary --smp-workers=1" ./knapsack_omp input-64.txt $i 9
		fi	
	done
done

