#!/bin/bash

#BSUB -n 1
#BSUB -J car_memo
#BSUB -oo car_memo.out
#BSUB -eo car_memo.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./car_memo input-50.txt $i 
	done
done

