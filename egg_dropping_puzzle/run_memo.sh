#!/bin/bash

#BSUB -n 1
#BSUB -J edp_memo 
#BSUB -oo edp_memo.out
#BSUB -eo edp_memo.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./edp_memo 10 $i 
	done
done

