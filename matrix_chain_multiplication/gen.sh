#!/bin/bash
range=100

for i in `seq 1 $1`
do
    value=$RANDOM
    let "value %= $range"
    let "value += 1"
    echo $value >> $2
done
