#!/bin/bash

#BSUB -n 1
#BSUB -J levenshtein_distance_omp 
#BSUB -oo levenshtein_distance_omp.out
#BSUB -eo levenshtein_distance_omp.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./levenshtein_distance_omp abcdefghij zyxwvutsrqponml 3 
		elif test $i -eq 2
		then
			./levenshtein_distance_omp abcdefghij zyxwvutsrqponmlk 3
		elif test $i -eq 3
		then
			./levenshtein_distance_omp abcdefghij zyxwvutsrqponmlkj 3
		elif test $i -eq 4
		then
			./levenshtein_distance_omp abcdefghij zyxwvutsrqponmlkji 3
		else
			./levenshtein_distance_omp abcdefghij zyxwvutsrqponmlkjih 3
		fi
	done
done
