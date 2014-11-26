#!/bin/bash

#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -q debug
#BSUB -J test
#BSUB -oo test1.out
#BSUB -eo test1.err
#BSUB -W 00:10

NX_ARGS="--summary" ./fib_omp_memo_table 36 14 2>> outputs_table 1>> outputs_table
