#!/bin/bash

#BSUB -n 1
#BSUB -J mcp_memo 
#BSUB -oo mcp_memo.out
#BSUB -eo mcp_memo.err
#BSUB -W 00:10

for i in {11..15} 
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		./mcp_memo input-50x50.txt 16 16 $i 11 
	done
done

