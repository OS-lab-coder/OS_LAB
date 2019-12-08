#! /bin/bash

echo -n "Enter Number : "
read N
num=$N
c=''
while [ $N -ne 0 ]
do
	ll=$((N%10))
	c=$c$ll
	N=$((N/10))
done 
if [ $c -eq $num ]
then
	echo "yes"
else 
	echo "No"
fi

