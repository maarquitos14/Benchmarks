#!/bin/bash

#BSUB -n 1
#BSUB -J lis_memo 
#BSUB -oo lis_memo.out
#BSUB -eo lis_memo.err
#BSUB -W 00:10

for i in 130 135 140 145 150 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./lis_memo input-200.txt $i 
	done
done

