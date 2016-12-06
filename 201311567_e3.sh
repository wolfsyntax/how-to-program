#!/bin/bash

#-------------------------------------------------------------------------#
# Filename        : 201311567_e3.sh                                       #
# Author          : Jayson D. Alpe                                        #
# Course and Year : BSIT-3                                                      #
# Last Modified   : December 6, 2016                                                      #
# Honor Code      : This is my own code. I have worked hard in completing #
#                   this work and I have not copied from any unauthorized #
#                   resource. I am also well aware of the policies        #
#                   stipulated in the college student handbook regarding  #
#                   academic dishonesty.                                  #
#-------------------------------------------------------------------------#

if [[ $# -ne 1 ]]; then
	echo -e "Usage: $0 n\nThe script needs a positive integer n as argument."
	exit
fi

if [[ $1 -le 0 ]]; then
	echo -e "Usage: $0 n\nThe script needs a positive integer n as argument."
	exit
fi

rm *.txt


r=1
p1=0
p2=1

ctr=0

if [[ $ctr -eq 0 ]]; then
	echo "" > 0.txt
fi


while [[ $ctr -lt $1 ]]; do
	echo "" > $r.txt	
	r=`expr $p1 + $p2`
	
	p1=$p2
	p2=$r
	
	ctr=`expr $ctr + 1`			
	
	
done

ls *.txt

