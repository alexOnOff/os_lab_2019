#!/bin/bash

for ((i=0;i<150;i++))
do
rand=$(od -N 1 -t uL -An /dev/random | tr -d " ")
echo $rand >> $1
done