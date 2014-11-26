#!/bin/bash

#BSUB -n 1
#BSUB -J edp
#BSUB -oo edp.out
#BSUB -eo edp.err
#BSUB -W 00:10

for i in {17..21}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./edp 10 $i 
	done
done

