#!/bin/bash;
#!chmod777%; 

# When file exists, not create the directory 
mkdir directory; 
cd directory/;

# Scanf of variables
read NAMEFILE
clear;
touch $NAMEFILE.txt;

# Variables can't have spaces
FILE=$NAMEFILE.txt;
echo Hello World! > $FILE;

# Crasis make the variable receive the output of command, not the command
# Passing the output of echo to input de wc
COUNTCHAR=`cat $FILE | wc -c`;
echo Double of characters: $[COUNTCHAR * 2] >> $FILE;
declare -i varInt
varInt=$COUNTCHAR/2 && echo Int half of characters: $varInt >> $FILE

echo "O nome deste script é: $0"
echo "Recebidos $# argumentos: $*"
echo "O primeiro argumento recebido foi: $1"