#! /bin/bash
echo enter three number
read a
read b
read c
if [ $a -gt $b ]
then
        if [ $a -gt $c ]
        then
                echo Max is $a
        else
                echo Max is $c
        fi
else
        if [ $b -gt $c ]
        then
                echo Max is $b
        else
                echo Max is $c
        fi
fi
