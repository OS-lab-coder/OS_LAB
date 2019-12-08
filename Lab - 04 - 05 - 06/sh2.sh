#!/bin/bash 
echo "Calender : ";cal 
echo "Date : ";date +"%d/%m/%y";echo "" 
echo "Time : ";date +"%T";echo "" 
check=`date +%H` 
if [ $check -gt 6 -a $check -lt 12 ] 
then echo "Good Morning" 
elif [ $check -ge 12 -a $check -lt 18 ] 
then echo "Good Afternoon" 
11 
 
 
else echo "Good Evening" 
fi 
echo "" 
echo "User name : ";whoami;echo "" 
echo "Home directory : ";echo $HOME;echo "" 
echo "Terminal name : ";tty;echo "" 
echo "Terminal Type : ";echo $TERM;echo "" 
echo "Machine name : ";uname -a;echo "" 
echo "Number of users currently logged in : ";users | wc -w 
