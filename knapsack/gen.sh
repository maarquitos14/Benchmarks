#!/bin/bash
rango_valor=1000
rango_peso=400

for i in `seq 1 $1`
do
    peso=$RANDOM
    valor=$RANDOM
    let "peso %= $rango_peso"
    let "valor %= $rango_valor"
    echo $peso,$valor >> $2
done
