
#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo knapsack_inst.out
#BSUB -eo knapsack_inst.err
#BSUB -J knapsack_inst 
#BSUB -x
#BSUB -W 00:10

NX_ARGS="--smp-workers=8 --instrumentation=extrae" ./knapsack_omp_memo_inst input-100000.txt 147 146 
NX_ARGS="--smp-workers=8 --instrumentation=extrae" ./knapsack_omp_inst input-100000.txt 147 45 
