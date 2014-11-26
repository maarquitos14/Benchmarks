#!/bin/bash

#BSUB -n 1
#BSUB -J coin_change_omp_memo 
#BSUB -oo coin_change_omp_memo.out
#BSUB -eo coin_change_omp_memo.err
#BSUB -W 00:10

for i in 115 125 135 145 155 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=1" ./coin_change_omp_memo input-10.txt 10 $i 3 
	done
done

