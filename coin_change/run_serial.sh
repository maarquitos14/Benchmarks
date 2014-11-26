#!/bin/bash

#BSUB -n 1
#BSUB -J coin_change
#BSUB -oo coin_change.out
#BSUB -eo coin_change.err
#BSUB -W 00:10

for i in 115 125 135 145 155 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./coin_change input-10.txt 10 $i 
	done
done

