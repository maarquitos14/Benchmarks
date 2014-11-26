#!/bin/bash

#BSUB -n 1
#BSUB -J mcm_omp_memo 
#BSUB -oo mcm_omp_memo.out
#BSUB -eo mcm_omp_memo.err
#BSUB -W 00:10

for i in {18..22} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 19
		then
			NX_ARGS="--summary --smp-workers=1" ./mcm_omp_memo input-100.txt $i 3 
		elif test $i -le 21
		then
			NX_ARGS="--summary --smp-workers=1" ./mcm_omp_memo input-100.txt $i 4 
		else
			NX_ARGS="--summary --smp-workers=1" ./mcm_omp_memo input-100.txt $i 5 
		fi	
	done
done

