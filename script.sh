#!/usr/bin/bash

#x=50
#while [ $x -le 2000 ]
#do
#  ./serf $x
#
#  x=$(( $x + 50 ))
#done

y=50
while [ $y -le 2000 ]
do
  ./omp $y

  y=$(( $y + 50 ))
done

z=50
while [ $z -le 2000 ]
do
  ./pt $z 2

  z=$(( $z + 50 ))
done
