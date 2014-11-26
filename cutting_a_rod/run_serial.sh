#!/bin/bash

#BSUB -n 1
#BSUB -J car
#BSUB -oo car.out
#BSUB -eo car.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./car input-50.txt $i 
	done
done

