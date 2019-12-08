#!/bin/bash 
IFS= 
echo "File one : " 
echo `cat $1` 
echo "File two : " 
echo `cat $2` 
`paste $1 $2 > Horizontal` 
echo "Horizontal : " 
echo `cat Horizontal` 
echo "Vertical : " 
`cat $1 $2 > Vertical` 
echo `cat Vertical` 
