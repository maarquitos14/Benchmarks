#!/bin/bash

#BSUB -q debug 
#BSUB -n 16
#BSUB -R "span[ptile=16]"
#BSUB -oo levenshtein_distance_strong_scaling.out
#BSUB -eo levenshtein_distance_strong_scaling.err
#BSUB -J levenshtein_distance_strong_scaling 
#BSUB -x
#BSUB -W 00:10

echo "levenshtein_distance_omp"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./levenshtein_distance_omp abcdefghij zyxwvutsrqponmlkjih 3
	done
done

echo "levenshtein_distance_omp_memo"

for i in 1 2 4 8 16 
do
	echo "Number of threads: $i"
	for j in {1..5}
	do
		NX_ARGS="--summary --smp-workers=$i" ./levenshtein_distance_omp_memo abcdefghij zyxwvutsrqponmlkjih 6
	done
done
