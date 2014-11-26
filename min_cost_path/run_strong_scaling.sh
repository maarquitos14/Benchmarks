#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mcp_strong_scaling.out
#BSUB -eo mcp_strong_scaling.err
#BSUB -J mcp_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "mcp_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./mcp_omp input-50x50.txt 16 16 15 11 4
	done
done

echo "mcp_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./mcp_omp_memo input-50x50.txt 16 16 15 11 5
	done
done
