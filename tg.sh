#!/bin/bash

for i in `seq 1 $2`; 
do
  ./tg $3 > idir/$1$i'.txt'  
done
