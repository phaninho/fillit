tests="../bin/fillit_test"
srcs="../bin/fillit"
rouge="\033[1;91m"
green="\033[1;92m"
none="\033[0m"


for FILE in ../maps/bad_map*
do
	if [ -f $FILE ]
	then
		str1=`$tests $FILE`
		str2=`$srcs $FILE`
		echo "$FILE: \c"
		if [ "$str2" = "error" ]
		then
			echo ${green}OK ${none}
		else
			echo ${rouge}F ${none}
		fi
	fi
done


