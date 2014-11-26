#!/bin/bash

#BSUB -n 1
#BSUB -J bst_omp_memo
#BSUB -oo bst_omp_memo.out
#BSUB -eo bst_omp_memo.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 17
		then
			NX_ARGS="--summary --smp-workers=1" ./bst_omp_memo $i 4
		elif test $i -le 19
		then
			NX_ARGS="--summary --smp-workers=1" ./bst_omp_memo $i 5
		elif test $i -le 20 
		then
			NX_ARGS="--summary --smp-workers=1" ./bst_omp_memo $i 6
		else
			NX_ARGS="--summary --smp-workers=1" ./bst_omp_memo $i 7
		fi	
	done
done

