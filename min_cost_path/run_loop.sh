#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mcp.out
#BSUB -eo mcp.err
#BSUB -J mcp 
#BSUB -x
#BSUB -W 00:30

rm outputs_map_of outputs_map_mf outputs_table_of outputs_table_mf

for i in {32..36}
do
    echo "Problem size $i" >> outputs_map_of
    echo "Problem size $i" >> outputs_map_mf
    echo "Problem size $i" >> outputs_table_of
    echo "Problem size $i" >> outputs_table_mf
    for j in {1..5}
    do
        NX_ARGS="--summary" ./mcp_omp_memo_map_of input-50x50.txt 50 50 $i 11 7 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mcp_omp_memo_map_mf input-50x50.txt 50 50 $i 11 7 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mcp_omp_memo_table_of input-50x50.txt 50 50 $i 11 7 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mcp_omp_memo_table_mf input-50x50.txt 50 50 $i 11 7 2>> outputs_table_mf 1>> outputs_table_mf
    done
done    
