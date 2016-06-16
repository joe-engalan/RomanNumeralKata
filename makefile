
kata : main.o
	gcc -o kata main.o

main.o : main.c
	gcc -c main.c

romanconverter.o : romanconverter.c romanconverter.h
	gcc -c romanconverter.c

all : clean romanconverter-test kata

test : romanconverter-test
	./romanconverter-test

romanconverter-test : romanconverter.o romanconverter-tests.o
	gcc -Wall -o romanconverter-test romanconverter-tests.o romanconverter.o -lcheck

romanconverter-tests.o : romanconverter.h romanconverter-tests.c
	gcc -c romanconverter-tests.c

.PHONY : clean
clean :
	rm -f romanconverter-test kata *.o
