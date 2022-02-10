#!/usr/bin/bash

# ^ path to the location of bash
# find path using "which bash"


# -----------TOPICS-------------- 
# ECHO COMMAND
# VARIABLES
# USER INPUT
# SIMPLE IF STATEMENT
# IF-ELSE
# ELSE-IF (elif)
# COMPARISON
# FILE CONDITIONS
# FILE COMMANDS
# CASE STATEMENT
# SIMPLE FOR LOOP
# FOR LOOP TO RENAME FILES
# FOR LOOP WITH RANGE
# FOR LOOP WITH CONDITION
# WHILE LOOP
# UNTIL LOOP
# FUNCTION
# FUNCTION WITH PARAMS
# CREATE FOLDER AND WRITE TO A FILE
# STDIN
# STDOUT and STDERR
# OUTPUT TO FILES
# GREP (GNU REGULAR EXPRESSION)
# AWK 
# SED
# SED -E


# ECHO COMMAND: print to terminal
echo Hello World!

# VARIABLES
# Uppercase by convention: letters, numbers, underscores
# use $ to access the variable's content
NAME="Joe"
echo "My name is $NAME"
# or: echo "My name is ${NAME}"

# USER INPUT
# read -p "Enter your name: " INPUT
# echo "Hello $INPUT, nice to meet you!"

# SIMPLE IF STATEMENT
# if [ "$NAME" == "Brad" ]
# then 
#     echo "Your name is Brad"
# fi

# IF-ELSE
# if [ "$NAME" == "Brad" ]
# then 
#     echo "Your name is Brad"
# else
#     echo "This ain't Brad!"
# fi

# ELSE-IF (elif)
if [ "$NAME" == "Brad" ]
then 
    echo "Your name is Brad"
elif [ "$NAME" == "Joe" ]
then 
    echo "Your name is Joe"
else
    echo "This ain't Brad or Joe!"
fi

# COMPARISON
NUM1=3
NUM2=5
if [ $NUM1 -gt $NUM2 ]
then 
    echo "$NUM1 is greater than $NUM2"
else
    echo "$NUM1 is less than $NUM2"
fi

#----------------
# val1 -eq val2 : Returns true if the values are equal
# val1 -ne val2 : Returns true if the values are not equal
# val1 -gt val2 : Returns true if val1 is greater than val2
# val1 -ge val2 : Returns true if val1 is greater than or equal to val2
# val1 -lt val2 : Returns true if val1 is less than val2
# val1 -le val2 : Returns true if val1 is less than or equal to val2
#----------------

# FILE CONDITIONS
FILE="test.txt"
if [ -f $FILE ]
then 
    echo "$FILE is a file"
else
    echo "$FILE is not a file"
fi

#----------------
# -d file : True if the file is a directory
# -e file : True if the file exists (-f is generally used)
# -f file : True if the provided string is a file
# -g file : True if the group id is set on a file
# -r file : True if the file is readable
# -s file : True if the file has a non-zero size
# -u file : True if the user id is set on a file
# -w file : True if the file is writable
# -x file : True if the file is an executable
#----------------

# FILE COMMANDS
# touch <file> : creates a file
# rm <file> : deletes a file
# mkdir <dir> : make a directory
# rmdir <dir> : deletes a directory

# CASE STATEMENT
# read -p "Are you 21 or over? Y/N " ANSWER 
# case $ANSWER in
#     [yY] | [yY][eE][sS])    # | is logical or
#         echo "You can drink some beer :)"
#         ;;
#     [nN] | [nN][oO])    # case insensive 
#         echo "Sorry, no drinking :("
#         ;;
#     *)
#         echo "Please enter y/yes or n/no"
#         ;;
# esac

# SIMPLE FOR LOOP
ELEMENTS="Carbon Gold Radon Sodium"
for EL in $ELEMENTS
    do 
        echo "I like $EL"
done

# FOR LOOP TO RENAME FILES
# FILES=$(ls *.txt)   # interesting, it runs a command here
# NEW="new"
# for F in $FILES
#     do 
#         echo "Renaming $F to new-$F"
#         mv $F $NEW-$F
# done

# FOR LOOP WITH RANGE
# for i in {0..10..2}
#     do 
#         echo $i
# done

# FOR LOOP WITH CONDITION
# BREAK AND CONTINUE
for (( i=0; i<=10; i++ ))
    do
        if [ $i -gt 5 ]
        then 
            break
        elif [ $i -eq 3 ]
        then 
            echo "It's a 3!"
            continue
        fi
        echo $i
done

# WHILE LOOP
# # READ THROUGH A FILE LINE BY LINE

# LINE=1
# while read -r CURRENT_LINE
#     do 
#         echo "$LINE: $CURRENT_LINE"
#         ((LINE++))  # iterate by 1
# done < "./new-1.txt"

# UNTIL LOOP
# NUM3=1
# while stops when cond is false
# until stops when cond is true

# until [ $NUM3 -ge 10 ]  
#     do 
#         echo "$NUM3"
#         ((NUM3++))
# done


# FUNCTION
function sayHello() {
    echo "Hello Hellish Demons!"
}

sayHello

# FUNCTION WITH PARAMS
function greet() {
    echo "Hello, I am $1 and I am $2"
}

greet "Valentine" "36"

# CREATE FOLDER AND WRITE TO A FILE
# mkdir hello
# touch "hello/world.txt"
# echo "Hello World" > "hello/world.txt"
# echo "Created hello/world.txt"

# STDIN
# echo $0 $1 $2 $3    # $0 is the script name, $1,2,3 are user provided inputs
# args=("$@")     # array with unlimited elements
# echo ${args[0]} ${args[1]} ${args[2]}   # similar to above
# echo $@     # echo everything provided
# echo $#     # echo number of elements 

# STDOUT and STDERR
ls -al 1> stdout.txt 2> stderr.txt  # 1 refers to STDOUT, 2 refers to STDERR
# ls -al >& stdout.txt      # directs both STDOUT and STDERR to both files

# OUTPUT TO FILES
# echo "What the pp?" > "new-2.txt"   # single > replaces text
# echo "What's next?" >> "new-2.txt"  # double >> appends text
# cat >> "new-2.txt"  # you can write text in the terminal, Ctrl-D to stop

# GREP (GNU REGULAR EXPRESSION)
# read -p "Input filename to search text from: " FILENAME 

# if [ -f $FILENAME ]
# then
#     echo "Find the file!"
#     read -p "Enter the text to search: " GREPVAR
#     grep -i -n -c $GREPVAR $FILENAME     
#     # -i to remove case sensitivity
#     # -n to output line numbers
#     # -c to return a count
#     # -v to show the number of lines w/o $GREPVAR
# else
#     echo "$FILENAME doesn't exist!"
# fi

# AWK 
# whole separate script, a lot of uses
# read -p "Input filename to search text from: " FILENAME 

# if [ -f $FILENAME ]
# then
#     echo "Found the file!"
#     awk '/kaon/ {print $2, $4}' $FILENAME
#     # find lines with 'pion' in FILENAME
#     # then print the 2nd column of those lines
# else
#     echo "$FILENAME doesn't exist!"
# fi

# SED
sed 's/i/I/2' sedfile.txt
# other convention: cat sedfile.txt | sed 's/i/I/g'
# s : for subsitution
# i : letter to replace
# I : letter to substitute

# note that only the first i of each line is replaced 
# to change all i, use 's/i/I/g', where g = global
# to change the second i of each line, use 's/i/I/2'

# use pipes to run sed on command outputs
# ls | sed 's/txt/docx/g' 

# SED -E
# the -e flag allows you to chain scripts
ls | sed -e 's/txt/docx/g' -e '/new/d' -e '/std/a\nice' 
# this will first substitute 'txt' with 'docx' 
# then it will delete the lines with 'new'
# then it will append 'nice' in the line after lines with 'std'
  
