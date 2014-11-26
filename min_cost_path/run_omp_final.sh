#!/bin/bash

#BSUB -n 1
#BSUB -J mcp_omp 
#BSUB -oo mcp_omp.out
#BSUB -eo mcp_omp.err
#BSUB -W 00:10

for i in {11..15} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 14 
		then
			NX_ARGS="--summary --smp-workers=1" ./mcp_omp input-50x50.txt 16 16 $i 11 3
		else
			NX_ARGS="--summary --smp-workers=1" ./mcp_omp input-50x50.txt 16 16 $i 11 4
		fi	
	done
done

