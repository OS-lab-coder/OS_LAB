#!/bin/bash 
 
if [ $# -gt 5 ];then 
echo "invalid number of Arguments" 
else 
n=$# 
args="$@" 
echo $args 
for i in $(seq $((n-1)) -1 0) 
15 
 
 
do 
echo $i 
#echo -n "${args[$i]}" 
done 
fi 
echo "" 
