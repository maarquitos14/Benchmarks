#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo lis.out
#BSUB -eo lis.err
#BSUB -J lis 
#BSUB -x
#BSUB -W 00:30

rm outputs_map_of outputs_map_mf outputs_table_of outputs_table_mf

for i in 170 175 180 185 190 
do
    echo "Problem size $i" >> outputs_map_of
    echo "Problem size $i" >> outputs_map_mf
    echo "Problem size $i" >> outputs_table_of
    echo "Problem size $i" >> outputs_table_mf
    for j in {1..5}
    do
        if test $i -le 175
        then
        NX_ARGS="--summary" ./lis_omp_memo_map_of input-200.txt $i 46 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./lis_omp_memo_map_mf input-200.txt $i 46 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./lis_omp_memo_table_of input-200.txt $i 46 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./lis_omp_memo_table_mf input-200.txt $i 46 2>> outputs_table_mf 1>> outputs_table_mf
	elif test $i -eq 180
	then
        NX_ARGS="--summary" ./lis_omp_memo_map_of input-200.txt $i 48 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./lis_omp_memo_map_mf input-200.txt $i 48 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./lis_omp_memo_table_of input-200.txt $i 48 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./lis_omp_memo_table_mf input-200.txt $i 48 2>> outputs_table_mf 1>> outputs_table_mf
	elif test $i -eq 185
	then
        NX_ARGS="--summary" ./lis_omp_memo_map_of input-200.txt $i 50 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./lis_omp_memo_map_mf input-200.txt $i 50 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./lis_omp_memo_table_of input-200.txt $i 50 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./lis_omp_memo_table_mf input-200.txt $i 50 2>> outputs_table_mf 1>> outputs_table_mf
        else
        NX_ARGS="--summary" ./lis_omp_memo_map_of input-200.txt $i 51 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./lis_omp_memo_map_mf input-200.txt $i 51 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./lis_omp_memo_table_of input-200.txt $i 51 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./lis_omp_memo_table_mf input-200.txt $i 51 2>> outputs_table_mf 1>> outputs_table_mf
        fi
    done
done    