#!/bin/bash

#BSUB -n 1
#BSUB -J lis
#BSUB -oo lis.out
#BSUB -eo lis.err
#BSUB -W 00:10

for i in 130 135 140 145 150 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./lis input-200.txt $i 
	done
done

