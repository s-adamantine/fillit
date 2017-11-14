#!/bin/bash -e

gcc -o test_fillit *.c -L. -lft

timeout() {
	time=$1
	command="/bin/sh -c \"$2\""
	expect -c "set echo \"-noecho\"; set timeout $time; spawn -noecho $command; expect timeout { exit 1 } eof { exit 0 }"
	if [ $? = 1 ] ; then
		echo ""
		echo "\033[37m		Timeout after ${time} seconds"
		echo ""
		echo "\033[31m------------------------------------------------"
	fi
}

echo ""
echo "\033[34m------------------ DEMARRAGE -------------------"
if [ $1 -gt 0 ]
then
	echo""
	echo "\033[33m-------------------- N = 1 ---------------------"

	for i in 'seq 1 50'
	do
		python map_gen.py 1 > sample11.txt
		timeout 15 "./test_fillit sample11.txt > slim.txt"
		./solution_fillit sample11.txt > domi.txt
		diff slim.txt domi.txt > diff.txt
		if [ -s diff.txt ]
		then
			echo ""
			echo "\033[31m		Votre grille pour 1 :"
			cat slim.txt
			echo ""
			echo "\033[31m		  Solution pour 1 :"
			cat domi.txt
		else
			echo ""
			echo "\033[32m		[✔] Grille 1 bonne"
			echo ""
		fi
	done
fi
if [ $1 -gt 1 ]
then
	echo "\033[33m-------------------- N = 2 ---------------------"

	for i in 'seq 1 50'
	do
		python map_gen.py 2 > sample22.txt
		timeout 15 "./test_fillit sample22.txt > slim.txt"
		./solution_fillit sample22.txt > domi.txt
		diff slim.txt domi.txt > diff.txt
		if [ -s diff.txt ]
		then
			echo ""
			echo "\033[31m		Votre grille pour 2 :"
			cat slim.txt
			echo ""
			echo "\033[31m		  Solution pour 2 :"
			cat domi.txt
		else
			echo ""
			echo "\033[32m		[✔] Grille 2 bonne"
			echo ""
		fi
	done
fi
if [ $1 -gt 2 ]
then
	echo "\033[33m-------------------- N = 3 ---------------------"

	for i in 'seq 1 50'
	do
		python map_gen.py 3 > sample33.txt
		timeout 15 "./test_fillit sample33.txt > slim.txt"
		./solution_fillit sample33.txt > domi.txt
		diff slim.txt domi.txt > diff.txt
		if [ -s diff.txt ]
		then
			echo ""
			echo "\033[31m		Votre grille pour 3 :"
			cat slim.txt
			echo ""
			echo "\033[31m		  Solution pour 3 :"
			cat domi.txt
		else
			echo ""
			echo "\033[32m		[✔] Grille 3 bonne"
			echo ""
		fi
	done
fi
if [ $1 -gt 3 ]
then
echo "\033[33m-------------------- N = 4 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 4 > sample44.txt
	timeout 15 "./test_fillit sample44.txt > slim.txt"
	./solution_fillit sample44.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 4 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 4 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 4 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 4 ]
then
echo "\033[33m-------------------- N = 5 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 5 > sample55.txt
	timeout 15 "./test_fillit sample55.txt > slim.txt"
	./solution_fillit sample55.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 5 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 5 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 5 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 5 ]
then
echo "\033[33m-------------------- N = 6 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 6 > sample66.txt
	timeout 15 "./test_fillit sample66.txt > slim.txt"
	./solution_fillit sample66.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 6 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 6 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 6 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 6 ]
then
echo "\033[33m-------------------- N = 7 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 7 > sample77.txt
	timeout 15 "./test_fillit sample77.txt > slim.txt"
	./solution_fillit sample77.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 7 :"
		cat slim.txt
		echo ""
		echo "\033[31m	  	  Solution pour 7 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 7 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 7 ]
then
echo "\033[33m-------------------- N = 8 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 8 > sample88.txt
	timeout 30 "./test_fillit sample88.txt > slim.txt"
	./solution_fillit sample88.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 8 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 8 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 8 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 8 ]
then
echo "\033[33m-------------------- N = 9 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 9 > sample99.txt
	timeout 30 "./test_fillit sample99.txt > slim.txt"
	./solution_fillit sample99.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 9 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 9 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 9 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 9 ]
then
echo "\033[33m-------------------- N = 10 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 10 > sample1010.txt
	timeout 30 "./test_fillit sample1010.txt > slim.txt"
	./solution_fillit sample1010.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 10 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 10 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 10 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 10 ]
then
echo "\033[33m-------------------- N = 11 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 11 > sample1111.txt
	timeout 30 "./test_fillit sample1111.txt > slim.txt"
	./solution_fillit sample1111.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 11 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 11 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 11 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 11 ]
then
echo "\033[33m-------------------- N = 12 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 12 > sample1212.txt
	timeout 30 "./test_fillit sample1212.txt > slim.txt"
	./solution_fillit sample1212.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 12 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 12 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 12 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 12 ]
then
echo "\033[33m-------------------- N = 13 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 13 > sample1313.txt
	timeout 30 "./test_fillit sample1313.txt > slim.txt"
	./solution_fillit sample1313.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 13 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 13 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 13 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 13 ]
then
echo "\033[33m-------------------- N = 14 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 14 > sample1414.txt
	timeout 30 "./test_fillit sample1414.txt > slim.txt"
	./solution_fillit sample1414.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 14 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 14 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 14 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 14 ]
then
echo "\033[33m-------------------- N = 15 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 15 > sample1515.txt
	timeout 30 "./test_fillit sample1515.txt > slim.txt"
	./solution_fillit sample1515.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 15 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 15 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 15 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 15 ]
then
echo "\033[33m-------------------- N = 16 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 16 > sample1616.txt
	timeout 30 "./test_fillit sample1616.txt > slim.txt"
	./solution_fillit sample1616.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 16 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 16 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 16 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 16 ]
then
echo "\033[33m-------------------- N = 17 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 17 > sample1717.txt
	timeout 30 "./test_fillit sample1010.txt > slim.txt"
	./solution_fillit sample1717.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 17 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 17 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 17 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 17 ]
then
echo "\033[33m-------------------- N = 18 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 18 > sample1818.txt
	timeout 30 "./test_fillit sample1818.txt > slim.txt"
	./solution_fillit sample1818.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 18 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 18 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 18 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 18 ]
then
echo "\033[33m-------------------- N = 19 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 19 > sample1919.txt
	timeout 30 "./test_fillit sample1919.txt > slim.txt"
	./solution_fillit sample1919.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 19 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 19 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 19 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 19 ]
then
echo "\033[33m-------------------- N = 20 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 20 > sample2020.txt
	timeout 30 "./test_fillit sample2020.txt > slim.txt"
	./solution_fillit sample2020.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 20 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 20 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 20 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 20 ]
then
echo "\033[33m-------------------- N = 21 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 21 > sample2121.txt
	timeout 30 "./test_fillit sample2121.txt > slim.txt"
	./solution_fillit sample2121.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 21 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 21 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 21 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 21 ]
then
echo "\033[33m-------------------- N = 22 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 10 > sample2222.txt
	timeout 30 "./test_fillit sample2222.txt > slim.txt"
	./solution_fillit sample2222.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 22 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 22 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 22 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 22 ]
then
echo "\033[33m-------------------- N = 23 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 23 > sample2323.txt
	timeout 30 "./test_fillit sample2323.txt > slim.txt"
	./solution_fillit sample1010.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 23 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 23 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 23 bonne"
		echo ""
	fi
done
fi
if [ $1 -gt 23 ]
then
echo "\033[33m-------------------- N = 24 ---------------------"

for i in 'seq 1 50'
do
	python map_gen.py 24 > sample2424.txt
	timeout 30 "./test_fillit sample2424.txt > slim.txt"
	./solution_fillit sample2424.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m		Votre grille pour 24 :"
		cat slim.txt
		echo ""
		echo "\033[31m		  Solution pour 24 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m		[✔] Grille 24 bonne"
		echo ""
	fi
done
fi

echo "\033[33m-------------------- Error 1 --------------------"

for i in 'seq 1 50'
do
	timeout 15 "./test_fillit errors.txt > slim.txt"
	./solution_fillit errors.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m          Votre grille pour error 1 :"
		cat slim.txt
		echo ""
		echo "\033[31m            Solution pour error 1 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m          [✔] Grille erreur 1 bonne"
		echo ""
	fi
done

echo "\033[33m-------------------- Error 2 --------------------"

for i in 'seq 1 50'
do
	timeout 15 "./test_fillit errors2.txt > slim.txt"
	./solution_fillit errors2.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m          Votre grille pour error 2 :"
		cat slim.txt
		echo ""
		echo "\033[31m            Solution pour error 2 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m          [✔] Grille erreur 2 bonne"
		echo ""
	fi
done

echo "\033[33m-------------------- Error 3 --------------------"

for i in 'seq 1 50'
do
	timeout 15 "./test_fillit errors3.txt > slim.txt"
	./solution_fillit errors3.txt > domi.txt
	diff slim.txt domi.txt > diff.txt
	if [ -s diff.txt ]
	then
		echo ""
		echo "\033[31m          Votre grille pour error 3 :"
		cat slim.txt
		echo ""
		echo "\033[31m            Solution pour error 3 :"
		cat domi.txt
	else
		echo ""
		echo "\033[32m          [✔] Grille erreur 3 bonne"
		echo ""
	fi
done

rm diff.txt
rm domi.txt
rm slim.txt
rm sample*
