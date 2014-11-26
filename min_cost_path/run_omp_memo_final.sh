#!/bin/bash

#BSUB -n 1
#BSUB -J mcp_omp_memo 
#BSUB -oo mcp_omp_memo.out
#BSUB -eo mcp_omp_memo.err
#BSUB -W 00:10

for i in {11..15} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -le 14
		then
			NX_ARGS="--summary --smp-workers=1" ./mcp_omp_memo input-50x50.txt 16 16 $i 4 
		else
			NX_ARGS="--summary --smp-workers=1" ./mcp_omp_memo input-50x50.txt 16 16 $i 5 
		fi	
	done
done

