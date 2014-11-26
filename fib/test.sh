#!/bin/bash

#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -q debug
#BSUB -J test
#BSUB -oo test.out
#BSUB -eo test.err
#BSUB -W 00:10

NX_ARGS="--summary" ./fib_omp_memo 36 14 2>> outputs_map 1>> outputs_map
