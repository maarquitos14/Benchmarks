#!/bin/bash

#BSUB -n 1
#BSUB -J test
#BSUB -oo test.out
#BSUB -eo test.err
#BSUB -W 00:30

for i in {21..25}
do
	echo "Problem size: $i"
	./bst $i 
done
