#! bin/bash

echo -n Enter number :
read N
echo Yes number is prime number
for((i=2;i<N;i++))
do
        if [ $((N%i)) -eq 0 ]
        then
                echo Opps!!! Sorry Number is Not prime number
                break
        fi
done
