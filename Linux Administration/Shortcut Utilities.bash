#!/bin/bash
#Ethan Hammond
#Purpose: This script accepts the following commands as the first parameter and performs the UNIX command. This is used as shortcuts for normal UNIX commands.
#Last Revision Date: 11/21/22
#Variables:
#ARG1 = command entry
#ARG2 = original file
#ARG3 = destination file

#Read arguments ..
ARG1=$1 #command entry
ARG2=$2 #original file
ARG3=$3 #destination file

#Function to check the file type being manipulated
function checkFile()
{

FILE=$ARG2
DFILE=$ARG3
FILE2=$VAR
DFILE2=$VAR3

#If the file is a regular file
if [ -f $FILE ] | [ -f $FILE2 ]
then
     echo
     echo "This is a regular file."

#If the file is a directory
elif [ -d $FILE ] | [ -d $FILE2 ]
then
     echo
     echo "This is a directory."

#If the file exists
elif [ -e $FILE ] | [ -e $FILE2 ]
then
     echo
     echo "This file exists."

#If the file does not exist
else
     echo
     echo "This file does not exist."

fi

}

#Function to exit if the file overwrites
function checkov()

{

if [ -f $DFILE ] | [ -f $DFILE2 ]
then
     echo "This will overwrite the file at file path: $DFILE."
     echo "Command failed."
     echo
exit 0
elif [ -d $DFILE ] | [ -d $DFILE2 ]
then
     echo "This will overwrite the directory at file path: $DFILE."
     echo "Command failed."
     echo
exit 0

else
Y=1

fi

}


#Function to store the directory that the user is in into a VAR
function readCurrent()

{

CURRENTDIR=($( ls ))
ALLDIR=($( ls / ))
}

#Function for the manipulation of files
function dos2()

{



COMMAND="UNIX command ran: "

#Chooses a specific set of operations

case $ARG1 in
	#prints author info
	"author")
		echo
		echo "$COMMAND echo Ethan Hammond"
		echo
		echo Ethan Hammond
		echo
		echo "Command ran successfully."
		;;
	#prints file contents
	"type")
		echo
		echo "$COMMAND cat $ARG2"
		echo
		cat $ARG2
		echo
		echo "Command ran successfully."
		;;
	#Copies a file
	"copy")
		echo
		echo "$COMMAND cp $ARG2 $ARG3"
		echo
		checkov
		cp $ARG2 $ARG3
		echo
	if [ Y == 1 ]
	then
		echo "Command ran successfully."
	fi
		;;
	#Copies a file AND OVERWRITES
	"copy!")
		echo
		echo "$COMMAND cp $ARG2 $ARG3"
		echo
		cp $ARG2 $ARG3
		echo
		echo "Command ran successfully."
		;;
	#Rename a file
	"ren")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		checkov
		mv $ARG2 $ARG3
		echo
	if [ Y == 1 ]
	then
		echo "Command ran successfully."
	fi
		;;
	#Renames a file AND OVERWRITES
	"ren!")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		mv $ARG2 $ARG3
		echo
		echo "Command ran successfully."
		;;
	#Move a file
	"move")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		checkov
		mv $ARG2 $ARG3
		echo
	if [ Y == 1 ]
	then
		echo "Command ran successfully."
	fi
		;;
	#Moves a file AND OVERWRITES
	"move!")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		mv $ARG2 $ARG3
		echo
		echo "Command ran successfully."
		;;
	#Delete a file
	"del")
		echo
		echo "$COMMAND rm $ARG2"
		echo
		rm $ARG2
		echo
		echo "Command ran successfully."
		;;
	#Outputs a list of commands
	"help")
		echo "$COMMAND help"
		echo '-------------------------------------------------------- '
		echo ' '
		echo ' '
		echo 'options:'
		echo ' '
		echo ' '
		echo ' '
		echo 'author: prints author info (dosutil [author])'
		echo 'type: prints file contents (dosutil [type /filepath])'
		echo 'copy: copies a file to another file (dosutil [copy /filepath /new/filepath])'
		echo 'ren: renames a file (dosutil [ren original/filename new/filename)]'
		echo 'move: moves a file (dosutil [move original/filepath /new/filepath)]'
		echo 'del: deletes a file (dosutil [del /filepath])'
		echo 'help: prints a list of options (dosutil [help])'
		echo ' '
		echo ' '
		echo ' '
		echo '-------------------------------------------------------- '
		;;

	#Interactive mode
	*)
		echo
		echo 'Files in the current directory: '

esac

}

#If the user doesn't enter anything, enter interactive mode
if [[ $ARG3 == $ARG2 ]]
then

#Reads the current directory
echo 'List of current files in your directory: '
echo
readCurrent
echo

#Prompt the user to enter a file from the current directory
echo 'Please select a file or directory from your current directory:'
echo ${CURRENTDIR[*]}
echo
select VAR in ${CURRENTDIR[*]}

do

echo $VAR
break
done

#Create array for command select loop
SLCT=(type copy ren del move help copy\! move\! ren\!)

#Use the select loop for a command to be entered
select VAR2 in ${SLCT[*]}

do

echo $VAR2

break
done

#If the command covers 2 variables
if [ $VAR2 == "copy" ] | [ $VAR2 == "ren" ] | [ $VAR2 == "move" ] | [ $VAR2 == "copy!" ] | [ $VAR2 == "move!" ] | [ $VAR2 == "ren!" ]
then

#Use read for the destination file
echo 'Possible filepaths for destination file: '
echo ${ALLDIR[*]}
echo


VAR3=""
echo "Enter destination file path: "
stty -echo
read VAR3
stty echo
echo
echo $VAR3

fi

#rerun the switch case with input from $VAR2 and $VAR
function dos3()

{



COMMAND="UNIX command ran: "

#Chooses a specific set of operations

case $VAR2 in
	#prints author info
	"author")
		echo
		echo "$COMMAND echo Ethan Hammond"
		echo
		echo Ethan Hammond
		echo
		echo "Command ran successfully."
		;;
	#prints file contents
	"type")
		echo
		echo "$COMMAND cat $ARG2"
		echo
		cat $VAR
		echo
		echo "Command ran successfully."
		;;
	#Copies a file
	"copy")
		echo
		echo "$COMMAND cp $ARG2 $ARG3"
		echo
		checkov
		cp $VAR $VAR3
		echo
	if [ Z == 1 ]
	then
		echo "Command ran successfully."
	fi
		;;
	#Copies a file AND OVERWRITES
	"copy!")
		echo
		echo "$COMMAND cp $ARG2 $ARG3"
		echo
		cp $VAR $VAR3
		echo
		echo "Command ran successfully."
		;;
	#Rename a file
	"ren")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		checkov
		mv $VAR $VAR3
		echo
	if [ Z == 1 ]
	then
		echo "Command ran successfully."
	fi
		;;
	#Renames a file AND OVERWRITES
	"ren!")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		mv $VAR $VAR3
		echo
		echo "Command ran successfully."
		;;
	#Move a file
	"move")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		checkov
		mv $VAR $VAR3
		echo
	if [ Z == 1 ]
	then
		echo "Command ran successfully."
	fi
		;;
	#Moves a file AND OVERWRITES
	"move!")
		echo
		echo "$COMMAND mv $ARG2 $ARG3"
		echo
		mv $VAR $VAR3
		echo
		echo "Command ran successfully."
		;;
	#Delete a file
	"del")
		echo
		echo "$COMMAND rm $ARG2"
		echo
		rm $VAR
		echo
		echo "Command ran successfully."
		;;
	#Outputs a list of commands
	"help")
		echo "$COMMAND help"
		echo '-------------------------------------------------------- '
		echo ' '
		echo ' '
		echo 'options:'
		echo ' '
		echo ' '
		echo ' '
		echo 'author: prints author info (dosutil [author])'
		echo 'type: prints file contents (dosutil [type /filepath])'
		echo 'copy: copies a file to another file (dosutil [copy /filepath /new/filepath])'
		echo 'ren: renames a file (dosutil [ren original/filename new/filename)]'
		echo 'move: moves a file (dosutil [move original/filepath /new/filepath)]'
		echo 'del: deletes a file (dosutil [del /filepath])'
		echo 'help: prints a list of options (dosutil [help])'
		echo ' '
		echo ' '
		echo ' '
		echo '-------------------------------------------------------- '
		;;

	#Interactive mode
	*)
		echo
		echo 'Files in the current directory: '

esac

}

#run the script
dos3

#If the user does anything else, run the script normally
else

#Calls checkFile to show what kind of file it is and if it exists
checkFile

#Calls the function to run the manipulation
dos2

fi




#successful escape code
exit 0
