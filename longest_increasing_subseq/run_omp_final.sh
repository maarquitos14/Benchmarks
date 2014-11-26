#!/bin/bash

#BSUB -n 1
#BSUB -J lis_omp 
#BSUB -oo lis_omp.out
#BSUB -eo lis_omp.err
#BSUB -W 00:10

for i in 130 135 140 145 150 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 130 
		then
			NX_ARGS="--summary --smp-workers=1" ./lis_omp input-200.txt $i 9
		elif test $i -eq 135
		then
			NX_ARGS="--summary --smp-workers=1" ./lis_omp input-200.txt $i 12
		elif test $i -eq 140
		then
			NX_ARGS="--summary --smp-workers=1" ./lis_omp input-200.txt $i 18
		else
			NX_ARGS="--summary --smp-workers=1" ./lis_omp input-200.txt $i 19
		fi	
	done
done

