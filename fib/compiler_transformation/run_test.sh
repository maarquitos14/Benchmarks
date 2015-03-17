#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo fib.out
#BSUB -eo fib.err
#BSUB -J fib 
#BSUB -x
#BSUB -W 00:30

rm outputs_memo outputs_table outputs_table_cpp outputs_map

for i in 1000000 10000000 100000000 400000000
do
    let k=$i*2
    echo "Problem size $i, $k" >> outputs_memo
    echo "Problem size $i, $k" >> outputs_table
#echo "Problem size $i, $k" >> outputs_table_cpp
#echo "Problem size $i, $k" >> outputs_map
    for j in {1..5}
    do
        ./fib_memo $i $k 2>> outputs_memo 1>> outputs_memo
        ./fib_table $i $k 2>> outputs_table 1>> outputs_table
#./fib_table_cpp $i $k 2>> outputs_table_cpp 1>> outputs_table_cpp
#./fib_map $i $k 2>> outputs_map 1>> outputs_map
    done
done    
