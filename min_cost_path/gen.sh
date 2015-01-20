#!/bin/bash
range=100

for i in `seq 1 $1`
do
    for j in `seq 1 $2`
    do
        value=$RANDOM
        let "value %= $range"
        let "value += 1"
        echo -n "$value " >> $3
    done
    echo "" >> $3
done
