#!/bin/bash

#BSUB -n 1
#BSUB -J knapsack
#BSUB -oo knapsack.out
#BSUB -eo knapsack.err
#BSUB -W 00:10

for i in {32..36}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./knapsack input-64.txt $i 
	done
done

