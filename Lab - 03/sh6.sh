#! /bin/bash

echo -n "Enter Number : "
read N
for((i=N-1;i>=1;i--))
do
	((N=N*i))
done
echo -n "Ans : "
echo $N
