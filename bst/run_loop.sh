#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo bst.out
#BSUB -eo bst.err
#BSUB -J bst 
#BSUB -x
#BSUB -W 00:30

rm outputs_map_of outputs_map_mf outputs_table_of outputs_table_mf

for i in {62..66}
do
    echo "Problem size $i" >> outputs_map_of
    echo "Problem size $i" >> outputs_map_mf
    echo "Problem size $i" >> outputs_table_of
    echo "Problem size $i" >> outputs_table_mf
    for j in {1..5}
    do
        if test $i -eq 62
        then
        NX_ARGS="--summary" ./bst_omp_memo_map_of $i 47 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./bst_omp_memo_map_mf $i 47 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./bst_omp_memo_table_of $i 47 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./bst_omp_memo_table_mf $i 47 2>> outputs_table_mf 1>> outputs_table_mf
        else
        NX_ARGS="--summary" ./bst_omp_memo_map_of $i 48 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./bst_omp_memo_map_mf $i 48 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./bst_omp_memo_table_of $i 48 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./bst_omp_memo_table_mf $i 48 2>> outputs_table_mf 1>> outputs_table_mf
        fi
    done
done    
