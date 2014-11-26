#!/bin/bash

#BSUB -n 1
#BSUB -J bst
#BSUB -oo bst.out
#BSUB -eo bst.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./bst $i 
	done
done

