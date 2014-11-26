#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mcm.out
#BSUB -eo mcm.err
#BSUB -J mcm 
#BSUB -x
#BSUB -W 00:30

rm outputs_map_of outputs_map_mf outputs_table_of outputs_table_mf

for i in {34..38} 
do
    echo "Problem size $i" >> outputs_map_of
    echo "Problem size $i" >> outputs_map_mf
    echo "Problem size $i" >> outputs_table_of
    echo "Problem size $i" >> outputs_table_mf
    for j in {1..5}
    do
        if test $i -eq 34
        then
        NX_ARGS="--summary" ./mcm_omp_memo_map_of input-100.txt $i 15 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mcm_omp_memo_map_mf input-100.txt $i 15 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mcm_omp_memo_table_of input-100.txt $i 15 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mcm_omp_memo_table_mf input-100.txt $i 15 2>> outputs_table_mf 1>> outputs_table_mf
	elif test $i -eq 35
	then
        NX_ARGS="--summary" ./mcm_omp_memo_map_of input-100.txt $i 16 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mcm_omp_memo_map_mf input-100.txt $i 16 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mcm_omp_memo_table_of input-100.txt $i 16 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mcm_omp_memo_table_mf input-100.txt $i 16 2>> outputs_table_mf 1>> outputs_table_mf
	elif test $i -eq 36
	then
        NX_ARGS="--summary" ./mcm_omp_memo_map_of input-100.txt $i 17 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mcm_omp_memo_map_mf input-100.txt $i 17 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mcm_omp_memo_table_of input-100.txt $i 17 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mcm_omp_memo_table_mf input-100.txt $i 17 2>> outputs_table_mf 1>> outputs_table_mf
        else
        NX_ARGS="--summary" ./mcm_omp_memo_map_of input-100.txt $i 18 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mcm_omp_memo_map_mf input-100.txt $i 18 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mcm_omp_memo_table_of input-100.txt $i 18 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mcm_omp_memo_table_mf input-100.txt $i 18 2>> outputs_table_mf 1>> outputs_table_mf
        fi
    done
done    
