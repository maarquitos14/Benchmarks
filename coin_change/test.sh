#!/bin/bash

#BSUB -n 1
#BSUB -J test
#BSUB -oo test.out
#BSUB -eo test.err
#BSUB -W 00:30

for i in 155 168 183 197 214  
do
	echo "Problem size: $i"
	./coin_change input-10.txt 10 $i 
done

