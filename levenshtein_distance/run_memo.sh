#!/bin/bash

#BSUB -n 1
#BSUB -J levenshtein_distance_memo 
#BSUB -oo levenshtein_distance_memo.out
#BSUB -eo levenshtein_distance_memo.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./levenshtein_distance_memo abcdefghij zyxwvutsrqponml
		elif test $i -eq 2
		then
			./levenshtein_distance_memo abcdefghij zyxwvutsrqponmlk
		elif test $i -eq 3
		then
			./levenshtein_distance_memo abcdefghij zyxwvutsrqponmlkj
		elif test $i -eq 4
		then
			./levenshtein_distance_memo abcdefghij zyxwvutsrqponmlkji
		else
			./levenshtein_distance_memo abcdefghij zyxwvutsrqponmlkjih 
		fi
	done
done

