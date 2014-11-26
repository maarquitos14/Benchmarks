#!/bin/bash

#BSUB -n 1
#BSUB -J levenshtein_distance
#BSUB -oo levenshtein_distance.out
#BSUB -eo levenshtein_distance.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./levenshtein_distance abcdefghij zyxwvutsrqponml 
		elif test $i -eq 2
		then
			./levenshtein_distance abcdefghij zyxwvutsrqponmlk
		elif test $i -eq 3
		then
			./levenshtein_distance abcdefghij zyxwvutsrqponmlkj
		elif test $i -eq 4
		then
			./levenshtein_distance abcdefghij zyxwvutsrqponmlkji
		else
			./levenshtein_distance abcdefghij zyxwvutsrqponmlkjih
		fi
	done
done

