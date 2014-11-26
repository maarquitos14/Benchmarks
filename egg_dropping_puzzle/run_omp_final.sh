#!/bin/bash

#BSUB -n 1
#BSUB -J edp_omp 
#BSUB -oo edp_omp.out
#BSUB -eo edp_omp.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 18
		then
			NX_ARGS="--summary --smp-workers=1" ./edp_omp 10 $i 3
		else
			NX_ARGS="--summary --smp-workers=1" ./edp_omp 10 $i 4
		fi	
	done
done

