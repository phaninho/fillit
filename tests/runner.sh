tests=../bin/fillit_test
srcs=../bin/fillit
rouge="\033[1;91m"
green="\033[1;92m"
none="\033[0m"


for FILE in ../maps/*
do 
	if [ -f $FILE ]
	then
		str1=`$tests $FILE`
		str2=`$srcs $FILE`
		echo "JP: $str1"
		echo "STEPH: $str2"
		echo "$FILE: \c"
		if [  "$str1" = "$str2" ]
		then
			echo ${green}OK ${none}
		else
			echo ${rouge}F ${none}
		fi
		# echo $FILE
		# ../bin/fillit_test $FILE
	fi 
done


