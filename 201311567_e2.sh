#!/bin/bash

#-------------------------------------------------------------------------#
# Filename        :  201311567_e1.sh                                      #
# Author          :  Jayson D. Alpe                                       #
# Course and Year :  BSIT-3                                               #
# Last Modified   :  December 2, 2016                                     #
# Honor Code      : This is my own code. I have worked hard in completing #
#                   this work and I have not copied from any unauthorized #
#                   resource. I am also well aware of the policies        #
#                   stipulated in the college student handbook regarding  #
#                   academic dishonesty.                                  #
#-------------------------------------------------------------------------#

#Shell Control Structures

if [[ $# -ne 1 ]]; then
	
	echo -e "Usage: $0 name\nThis script requires one argument.\n"
	exit
		
else
	echo -e "Welcome, $1!"

	n=0
	sum=0
	two=2
	val=0

	while [[ $n -ge 0 ]]; do
		read -p "Enter a counting number: " n
		
		if [[ $n -ge 0 ]]; then
			i=0
			
			while [[ $i -le $n ]]; do
				val=`expr $i % $two`

				
				if [[ $val == 0 ]]; then
					sum=`expr $sum + $i`				
				fi
				i=`expr $i + 1`			
			done
			
		else
			echo "Oops! $n is not a counting number. Goodbye!"
			exit
		fi
		echo "The sum of even counting numbers up to $n is $sum"
		sum=0				
	done
fi
