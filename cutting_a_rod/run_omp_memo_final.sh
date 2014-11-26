#!/bin/bash

#BSUB -n 1
#BSUB -J car_omp_memo
#BSUB -oo car_omp_memo.out
#BSUB -eo car_omp_memo.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 28 
		then
			NX_ARGS="--summary --smp-workers=1" ./car_omp_memo input-50.txt $i 8
		elif test $i -le 29
		then
			NX_ARGS="--summary --smp-workers=1" ./car_omp_memo input-50.txt $i 9
		elif test $i -le 31 
		then
			NX_ARGS="--summary --smp-workers=1" ./car_omp_memo input-50.txt $i 10
		else
			NX_ARGS="--summary --smp-workers=1" ./car_omp_memo input-50.txt $i 11 
		fi	
	done
done

