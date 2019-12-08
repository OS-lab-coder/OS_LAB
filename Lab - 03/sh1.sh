#! /bin/bash

#for a in 1 2 3 4 5
#do	
#	b=1
#	while [ $a -eq $b ]
#	do
#		echo -n $b
#		((b=b+1))
#	done
#done

for((i=1;i<=5;i++))
do
	for((j=1;j<=i;j++))
	do
		echo -n '*'
	done
	echo
done
