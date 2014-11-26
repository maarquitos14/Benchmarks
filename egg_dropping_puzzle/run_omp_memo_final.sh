#!/bin/bash

#BSUB -n 1
#BSUB -J edp_omp_memo 
#BSUB -oo edp_omp_memo.out
#BSUB -eo edp_omp_memo.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 18
		then
			NX_ARGS="--summary --smp-workers=1" ./edp_omp_memo 10 $i 4
		elif test $i -le 19
		then
			NX_ARGS="--summary --smp-workers=1" ./edp_omp_memo 10 $i 5
		else
			NX_ARGS="--summary --smp-workers=1" ./edp_omp_memo 10 $i 6
		fi	
	done
done

