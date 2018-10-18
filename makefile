all : sieve.h sieve.c
	gcc -o sieve sieve.h sieve.c

run : 
	./sieve
