#!/bin/bash

#BSUB -n 1
#BSUB -J knapsack_memo 
#BSUB -oo knapsack_memo.out
#BSUB -eo knapsack_memo.err
#BSUB -W 00:10

for i in {32..36}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./knapsack_memo input-64.txt $i 
	done
done

