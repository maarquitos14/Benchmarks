#!/bin/bash

#BSUB -n 1
#BSUB -J lcs_memo 
#BSUB -oo lcs_memo.out
#BSUB -eo lcs_memo.err
#BSUB -W 00:10

for i in {1..5}
do
	echo "Problem size: $i"
	for j in {1..5}
	do
		if test $i -eq 1
		then
			./lcs_memo abcdefghijklmnopqr zyxwvutsrqponm 
		elif test $i -eq 2
		then
			./lcs_memo abcdefghijklmnopqr zyxwvutsrqponml 
		elif test $i -eq 3
		then
			./lcs_memo abcdefghijklmnopqr zyxwvutsrqponmlk 
		elif test $i -eq 4
		then
			./lcs_memo abcdefghijklmnopqr zyxwvutsrqponmlkj 
		else
			./lcs_memo abcdefghijklmnopqr zyxwvutsrqponmlkji 
		fi
	done
done

