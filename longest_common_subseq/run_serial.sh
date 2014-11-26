#!/bin/bash

#BSUB -n 1
#BSUB -J lcs
#BSUB -oo lcs.out
#BSUB -eo lcs.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./lcs abcdefghijklmnopqr zyxwvutsrqponm 
		elif test $i -eq 2
		then
			./lcs abcdefghijklmnopqr zyxwvutsrqponml 
		elif test $i -eq 3
		then
			./lcs abcdefghijklmnopqr zyxwvutsrqponmlk 
		elif test $i -eq 4
		then
			./lcs abcdefghijklmnopqr zyxwvutsrqponmlkj 
		else
			./lcs abcdefghijklmnopqr zyxwvutsrqponmlkji 
		fi
	done
done

