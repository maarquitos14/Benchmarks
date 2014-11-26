#!/bin/bash

#BSUB -n 1
#BSUB -J fib_memo 
#BSUB -oo fib_memo.out
#BSUB -eo fib_memo.err
#BSUB -W 00:10

#for i in {18..22}
for i in {43..47}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./fib_memo $i 
	done
done

