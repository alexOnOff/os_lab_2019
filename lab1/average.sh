#!/bin/bash

count=0
sum=0

for i in $(cat $1)
do
count=$(( $count + 1 ))
sum=$(( $sum + $i )) 
done

average=$(( $sum / $count ))

echo "Count - $count"
echo "Average number - $average"