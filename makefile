
kata : main.o
	gcc -o kata main.o

main.o : main.c
	gcc -c main.c

troman.o : toroman.c toroman.h
	gcc -c toroman.c

all : clean toroman-test kata

test : toroman-test
	./toroman-test

toroman-test : toroman.o toroman-tests.o
	gcc -Wall -o toroman-test toroman-tests.o toroman.o -lcheck

toroman-tests.o : toroman.h toroman-tests.c
	gcc -c toroman-tests.c

.PHONY : clean
clean :
	rm -f toroman-test kata *.o
