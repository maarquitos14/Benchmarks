#!/bin/bash

#BSUB -n 1
#BSUB -J levenshtein_distance_omp_memo 
#BSUB -oo levenshtein_distance_omp_memo.out
#BSUB -eo levenshtein_distance_omp_memo.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./levenshtein_distance_omp_memo abcdefghij zyxwvutsrqponml 5
		elif test $i -eq 2
		then
			./levenshtein_distance_omp_memo abcdefghij zyxwvutsrqponmlk 5
		elif test $i -eq 3
		then
			./levenshtein_distance_omp_memo abcdefghij zyxwvutsrqponmlkj 5
		elif test $i -eq 4
		then
			./levenshtein_distance_omp_memo abcdefghij zyxwvutsrqponmlkjh 5
		else
			./levenshtein_distance_omp_memo abcdefghij zyxwvutsrqponmlkjhi 6 
		fi
	done
done

