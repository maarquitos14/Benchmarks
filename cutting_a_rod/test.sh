#!/bin/bash

#BSUB -n 1
#BSUB -J test
#BSUB -oo test.out
#BSUB -eo test.err
#BSUB -W 00:10

for i in {32..36}
do
	echo "Problem size: $i"
	./car input-50.txt $i 
done
