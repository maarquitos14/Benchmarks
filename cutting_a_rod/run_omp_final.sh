#!/bin/bash

#BSUB -n 1
#BSUB -J car_omp
#BSUB -oo car_omp.out
#BSUB -eo car_omp.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 28
		then
			NX_ARGS="--summary --smp-workers=1" ./car_omp input-50.txt $i 5
		elif test $i -eq 29
		then
			NX_ARGS="--summary --smp-workers=1" ./car_omp input-50.txt $i 6
		elif test $i -le 31
		then
			NX_ARGS="--summary --smp-workers=1" ./car_omp input-50.txt $i 7
		else
			NX_ARGS="--summary --smp-workers=1" ./car_omp input-50.txt $i 8
		fi	
	done
done

