#!/bin/bash

#BSUB -n 1
#BSUB -J mcm
#BSUB -oo mcm.out
#BSUB -eo mcm.err
#BSUB -W 00:10

for i in {18..22} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./mcm input-100.txt $i 
	done
done

