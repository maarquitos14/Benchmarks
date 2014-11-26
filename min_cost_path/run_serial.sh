#!/bin/bash

#BSUB -n 1
#BSUB -J mcp
#BSUB -oo mcp.out
#BSUB -eo mcp.err
#BSUB -W 00:10

for i in {11..15} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./mcp input-50x50.txt 16 16 $i 11 
	done
done

