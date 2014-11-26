#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo mpc.out
#BSUB -eo mpc.err
#BSUB -J mpc 
#BSUB -x
#BSUB -W 00:30

rm outputs_map_of outputs_map_mf outputs_table_of outputs_table_mf

#for i in 65 70 75 80 85 
for i in 85
do
    echo "Problem size $i" >> outputs_map_of
    echo "Problem size $i" >> outputs_map_mf
    echo "Problem size $i" >> outputs_table_of
    echo "Problem size $i" >> outputs_table_mf
    for j in {1..5}
    do
        if test $i -eq 65
        then
        NX_ARGS="--summary" ./mpc_omp_memo_map_of $i 42 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mpc_omp_memo_map_mf $i 42 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mpc_omp_memo_table_of $i 42 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mpc_omp_memo_table_mf $i 42 2>> outputs_table_mf 1>> outputs_table_mf
	elif test $i -eq 70
	then
        NX_ARGS="--summary" ./mpc_omp_memo_map_of $i 47 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mpc_omp_memo_map_mf $i 47 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mpc_omp_memo_table_of $i 47 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mpc_omp_memo_table_mf $i 47 2>> outputs_table_mf 1>> outputs_table_mf
	elif test $i -eq 75
	then
        NX_ARGS="--summary" ./mpc_omp_memo_map_of $i 52 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mpc_omp_memo_map_mf $i 52 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mpc_omp_memo_table_of $i 52 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mpc_omp_memo_table_mf $i 52 2>> outputs_table_mf 1>> outputs_table_mf
	elif test $i -eq 80
	then
        NX_ARGS="--summary" ./mpc_omp_memo_map_of $i 57 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mpc_omp_memo_map_mf $i 57 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mpc_omp_memo_table_of $i 57 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mpc_omp_memo_table_mf $i 57 2>> outputs_table_mf 1>> outputs_table_mf
        else
        NX_ARGS="--summary" ./mpc_omp_memo_map_of $i 61 2>> outputs_map_of 1>> outputs_map_of
        NX_ARGS="--summary" ./mpc_omp_memo_map_mf $i 61 2>> outputs_map_mf 1>> outputs_map_mf
	NX_ARGS="--summary" ./mpc_omp_memo_table_of $i 61 2>> outputs_table_of 1>> outputs_table_of
	NX_ARGS="--summary" ./mpc_omp_memo_table_mf $i 61 2>> outputs_table_mf 1>> outputs_table_mf
        fi
    done
done    
