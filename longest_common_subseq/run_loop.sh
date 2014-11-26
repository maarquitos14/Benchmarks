#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo lcs.out
#BSUB -eo lcs.err
#BSUB -J lcs 
#BSUB -x
#BSUB -W 00:30

rm outputs_map_of outputs_map_mf outputs_table_of outputs_table_mf

for i in {1..5}
do
    echo "Problem size $i+22" >> outputs_map_of
    echo "Problem size $i+22" >> outputs_map_mf
    echo "Problem size $i+22" >> outputs_table_of
    echo "Problem size $i+22" >> outputs_table_mf
    echo "Problem size $i"
    for j in {1..5}
    do
        if test $i -eq 1
        then
	    NX_ARGS="--summary" ./lcs_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfed 9 2>> outputs_map_of 1>> outputs_map_of
	    NX_ARGS="--summary" ./lcs_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfed 9 2>> outputs_map_mf 1>> outputs_map_mf
	    NX_ARGS="--summary" ./lcs_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfed 9 2>> outputs_table_of 1>> outputs_table_of
	    NX_ARGS="--summary" ./lcs_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfed 9 2>> outputs_table_mf 1>> outputs_table_mf
        elif test $i -eq 2
        then
	    NX_ARGS="--summary" ./lcs_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedc 10 2>> outputs_map_of 1>> outputs_map_of
	    NX_ARGS="--summary" ./lcs_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedc 10 2>> outputs_map_mf 1>> outputs_map_mf
	    NX_ARGS="--summary" ./lcs_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedc 10 2>> outputs_table_of 1>> outputs_table_of
	    NX_ARGS="--summary" ./lcs_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedc 10 2>> outputs_table_mf 1>> outputs_table_mf
        elif test $i -eq 3
        then
	    NX_ARGS="--summary" ./lcs_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcb 10 2>> outputs_map_of 1>> outputs_map_of
	    NX_ARGS="--summary" ./lcs_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcb 10 2>> outputs_map_mf 1>> outputs_map_mf
	    NX_ARGS="--summary" ./lcs_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcb 10 2>> outputs_table_of 1>> outputs_table_of
	    NX_ARGS="--summary" ./lcs_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcb 10 2>> outputs_table_mf 1>> outputs_table_mf
        elif test $i -eq 4
        then
	    NX_ARGS="--summary" ./lcs_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcba 10 2>> outputs_map_of 1>> outputs_map_of
	    NX_ARGS="--summary" ./lcs_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcba 10 2>> outputs_map_mf 1>> outputs_map_mf
	    NX_ARGS="--summary" ./lcs_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcba 10 2>> outputs_table_of 1>> outputs_table_of
	    NX_ARGS="--summary" ./lcs_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcba 10 2>> outputs_table_mf 1>> outputs_table_mf
        else
	    NX_ARGS="--summary" ./lcs_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcbab 11 2>> outputs_map_of 1>> outputs_map_of
	    NX_ARGS="--summary" ./lcs_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcbab 11 2>> outputs_map_mf 1>> outputs_map_mf
	    NX_ARGS="--summary" ./lcs_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcbab 11 2>> outputs_table_of 1>> outputs_table_of
	    NX_ARGS="--summary" ./lcs_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjihgfedcbab 11 2>> outputs_table_mf 1>> outputs_table_mf
        fi
    done
done    
