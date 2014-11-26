#!/bin/bash

#BSUB -n 1
#BSUB -J knapsack_omp_memo 
#BSUB -oo knapsack_omp_memo.out
#BSUB -eo knapsack_omp_memo.err
#BSUB -W 00:10

for i in {32..36}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 34
		then
			NX_ARGS="--summary --smp-workers=1" ./knapsack_omp_memo input-64.txt $i 11 
		else
			NX_ARGS="--summary --smp-workers=1" ./knapsack_omp_memo input-64.txt $i 12
		fi	
	done
done

