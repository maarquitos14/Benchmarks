#!/bin/bash

#BSUB -n 1
#BSUB -J mcm_omp 
#BSUB -oo mcm_omp.out
#BSUB -eo mcm_omp.err
#BSUB -W 00:10

for i in {18..22} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 21 
		then
			NX_ARGS="--summary --smp-workers=1" ./mcm_omp input-100.txt $i 2
		else
			NX_ARGS="--summary --smp-workers=1" ./mcm_omp input-100.txt $i 3
		fi	
	done
done

