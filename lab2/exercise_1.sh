#!/bin/bash

target=$7
min=1
max=10
guessNumber(){
	while [ $num -ne $target ];do
		if [ $num -lt $min ] || [ $num -gt $max ];then
			echo "error!"
		elif [ $num -lt $target ];then
			min=`expr $num + 1`
		elif [ $num -gt $target ];then
			max=`expr $num - 1`
		fi
		echo "Please enter a number between $min and $max: \c"
		read num
	done
	echo "Bingo!"
}


echo "Welcome to the Number Guessing Game!"
echo "Please enter a number between $min and $max: \c"
read num
guessNumber;
