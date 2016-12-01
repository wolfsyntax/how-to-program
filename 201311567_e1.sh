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

#create a directory
mkdir Alpe
#Change directory
cd Alpe

#Create a text file containing a text
echo -e "Name,Age\n" > data.csv

#Prompt user to input details
read -p "What is your name?" name
read -p "How old are you?" age

#Append user input to the file
echo -e "$name,$age" >> data.csv

#Display the content of a file
cat data.csv

#list all files which start in capital letter D and display in recursive long format
ls -Rl D* > contents.txt
