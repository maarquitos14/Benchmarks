#!/bin/bash

#BSUB -n 1
#BSUB -J mpc_memo 
#BSUB -oo mpc_memo.out
#BSUB -eo mpc_memo.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./mpc_memo $i 
	done
done

