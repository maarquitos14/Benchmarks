#!/bin/bash

#BSUB -n 1
#BSUB -J mpc
#BSUB -oo mpc.out
#BSUB -eo mpc.err
#BSUB -W 00:10

for i in {28..32}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./mpc $i 
	done
done

