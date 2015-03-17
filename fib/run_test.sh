#!/bin/bash

#BSUB -q sequential 
#BSUB -n 1
#BSUB -oo fib_overhead.out
#BSUB -eo fib_overhead.err
#BSUB -J fib_overhead 
#BSUB -x
#BSUB -W 00:30

rm outputs_omp_memo_serial outputs_omp_compiler_transformation outputs_memo

for i in 100 1000 10000 100000 1000000 10000000 100000000 300000000 500000000
do
    echo "Problem size $i" >> outputs_omp_memo_serial
    echo "Problem size $i" >> outputs_omp_compiler_transformation
    echo "Problem size $i" >> outputs_memo
    for j in {1..5}
    do
        ./fib_memo $i 2>> outputs_memo 1>> outputs_memo
#        NX_ARGS="--pthreads-stack-size=20000000000" ./fib_omp_memo_serial $i 2>> outputs_omp_memo_serial 1>> outputs_omp_memo_serial
        ./fib1_compiler_transformation $i 2>> outputs_omp_compiler_transformation 1>> outputs_omp_compiler_transformation
    done
done    
