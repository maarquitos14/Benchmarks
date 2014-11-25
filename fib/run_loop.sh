#!/bin/bash

for i in {1..1000}
do
    ./fib_omp_memo 50 18
done

#for i in {72..76}
#do
#    for j in {1..5}
#    do
#        if test $i -le 74
#        then
#        ./fib_omp_memo $i 31
#        else
#        ./fib_omp_memo $i 32
#        fi
#    done
#done    
