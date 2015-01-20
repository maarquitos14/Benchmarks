#!/bin/bash
range=10

for i in `seq 1 $1`
do
    value=$RANDOM
    let "value %= $range"
    echo $value >> $2
done
