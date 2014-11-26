#!/bin/bash

#BSUB -n 1
#BSUB -J mcm_memo 
#BSUB -oo mcm_memo.out
#BSUB -eo mcm_memo.err
#BSUB -W 00:10

for i in {18..22} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./mcm_memo input-100.txt $i 
	done
done

