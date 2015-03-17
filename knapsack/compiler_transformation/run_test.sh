#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo knapsack.out
#BSUB -eo knapsack.err
#BSUB -J knapsack 
#BSUB -x
#BSUB -W 00:30

rm outputs_memo outputs_table outputs_table_cpp outputs_map

for i in 250 2500 25000 150000
do
    let k=$i*2
    echo "Problem size $i, $k" >> outputs_memo
    echo "Problem size $i, $k" >> outputs_table
#echo "Problem size $i, $k" >> outputs_table_cpp
#echo "Problem size $i, $k" >> outputs_map
    for j in {1..5}
    do
        ./knapsack_memo ../input-1000000.txt $i $k 2>> outputs_memo 1>> outputs_memo
        ./knapsack_table ../input-1000000.txt $i $k 2>> outputs_table 1>> outputs_table
#./knapsack_table_cpp ../input-1000000.txt $i $k 2>> outputs_table_cpp 1>> outputs_table_cpp
#./knapsack_map ../input-1000000.txt $i $k 2>> outputs_map 1>> outputs_map
    done
done    
