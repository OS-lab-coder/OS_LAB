#! /bin/bash 
echo -n "Enter Number : " 
read N 
for((i=1;i<=10;i++)) 
do 
    echo $N '*' $i '=' $((N*1)) 
done 
