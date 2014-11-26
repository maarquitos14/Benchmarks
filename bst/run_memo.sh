#!/bin/bash

#BSUB -n 1
#BSUB -J bst_memo
#BSUB -oo bst_memo.out
#BSUB -eo bst_memo.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./bst_memo $i 
	done
done

