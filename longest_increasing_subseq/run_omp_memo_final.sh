#!/bin/bash

#BSUB -n 1
#BSUB -J lis_omp_memo 
#BSUB -oo lis_omp_memo.out
#BSUB -eo lis_omp_memo.err
#BSUB -W 00:10

for i in 130 135 140 145 150 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 130
		then
			NX_ARGS="--summary --smp-workers=1" ./lis_omp_memo input-200.txt $i 14 
		elif test $i -eq 135
		then
			NX_ARGS="--summary --smp-workers=1" ./lis_omp_memo input-200.txt $i 20 
		elif test $i -le 145
		then
			NX_ARGS="--summary --smp-workers=1" ./lis_omp_memo input-200.txt $i 21 
		else
			NX_ARGS="--summary --smp-workers=1" ./lis_omp_memo input-200.txt $i 26
		fi	
	done
done

