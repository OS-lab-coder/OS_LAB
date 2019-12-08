#!/bin/bash 
ans=0 
for i in $@ 
do 
ans=$((ans+i)) 
done 
echo $ans 
