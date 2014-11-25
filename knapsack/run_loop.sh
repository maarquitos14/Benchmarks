#!/bin/bash

for i in {1..500}
do
    echo "Iteration $i"
    ./knapsack_omp_memo input-64.txt 35 14
done

#for i in {40..44}
#do
#    for j in {1..5}
#    do
#        if test $i -le 41
#        then
#        ./knapsack_omp_memo input-64.txt $i 14
#        elif test $i -eq 42
#        then
#        ./knapsack_omp_memo input-64.txt $i 15
#        else
#        ./knapsack_omp_memo input-64.txt $i 16
#        fi
#    done
#done    
