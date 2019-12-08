#!/bin/bash 
echo -n "Enter name of the user : " 
read name 
Logged=`users` 
for user in $Logged 
do 
if [ $user = $name ];then 
echo "User is Logged in currently" 
exit 
fi 
done 
echo "User not logged in currently" 