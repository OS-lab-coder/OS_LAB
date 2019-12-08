#!/bin/bash  n=$1 
ans=0 
while [ $n -ne 0 ] 
do 
r=$((n%10)) 
ans=$((ans+r)) 
n=$((n/10)) 
done 
if [ $((ans%2)) -eq 0 ]; then 
echo "Even" 
else echo "Odd" 
Fi 
