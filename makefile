all : sieve.h sieve.c
	gcc -o sieve sieve.c -lm

run :
	./sieve
