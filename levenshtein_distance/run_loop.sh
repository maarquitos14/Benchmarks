#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo levenshtein_distance.out
#BSUB -eo levenshtein_distance.err
#BSUB -J levenshtein_distance 
#BSUB -x
#BSUB -W 00:30

rm outputs_map_of outputs_map_mf outputs_table_of outputs_table_mf

for i in {1..5}
do
    echo "Problem size $i+14" >> outputs_map_of
    echo "Problem size $i+14" >> outputs_map_mf
    echo "Problem size $i+14" >> outputs_table_of
    echo "Problem size $i+14" >> outputs_table_mf
    for j in {1..5}
    do
        if test $i -eq 1
        then
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponml 9 2>> outputs_map_of 1>> outputs_map_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponml 9 2>> outputs_map_mf 1>> outputs_map_mf
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponml 9 2>> outputs_table_of 1>> outputs_table_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponml 9 2>> outputs_table_mf 1>> outputs_table_mf
        elif test $i -eq 2
        then
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlk 10 2>> outputs_map_of 1>> outputs_map_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlk 10 2>> outputs_map_mf 1>> outputs_map_mf
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlk 10 2>> outputs_table_of 1>> outputs_table_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlk 10 2>> outputs_table_mf 1>> outputs_table_mf
        elif test $i -eq 3
        then
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkj 10 2>> outputs_map_of 1>> outputs_map_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkj 10 2>> outputs_map_mf 1>> outputs_map_mf
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkj 10 2>> outputs_table_of 1>> outputs_table_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkj 10 2>> outputs_table_mf 1>> outputs_table_mf
        elif test $i -eq 4
        then
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkji 10 2>> outputs_map_of 1>> outputs_map_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkji 10 2>> outputs_map_mf 1>> outputs_map_mf
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkji 10 2>> outputs_table_of 1>> outputs_table_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkji 10 2>> outputs_table_mf 1>> outputs_table_mf
        else
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_of abcdefghijklmnopqrst zyxwvutsrqponmlkjih 10 2>> outputs_map_of 1>> outputs_map_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_map_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjih 10 2>> outputs_map_mf 1>> outputs_map_mf
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_of abcdefghijklmnopqrst zyxwvutsrqponmlkjih 10 2>> outputs_table_of 1>> outputs_table_of
            NX_ARGS="--summary" ./levenshtein_distance_omp_memo_table_mf abcdefghijklmnopqrst zyxwvutsrqponmlkjih 10 2>> outputs_table_mf 1>> outputs_table_mf
        fi
    done
done    
