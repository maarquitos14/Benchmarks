#!/bin/bash

#BSUB -n 1
#BSUB -J bst_omp
#BSUB -oo bst_omp.out
#BSUB -eo bst_omp.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 19
		then
			NX_ARGS="--summary --smp-workers=1" ./bst_omp $i 4
		elif test $i -eq 20
		then
			NX_ARGS="--summary --smp-workers=1" ./bst_omp $i 5
		else
			NX_ARGS="--summary --smp-workers=1" ./bst_omp $i 6
		fi	
	done
done

