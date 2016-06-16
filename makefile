
kata : main.o
	gcc -o kata main.o

main.o : main.c
	gcc -c main.c

romanconverter.o : romanconverter.c romanconverter.h
	gcc -c romanconverter.c

all : clean romanconverter-test kata

test : digitextractor-test romanconverter-test
	./romanconverter-test
	./digitextractor-test

romanconverter-test : romanconverter.o romanconverter-tests.o
	gcc -Wall -o romanconverter-test romanconverter-tests.o romanconverter.o -lcheck

digitextractor-test : romanconverter.o digitextractor-tests.o
	gcc -Wall -o digitextractor-test digitextractor-tests.o romanconverter.o -lcheck

romanconverter-tests.o : romanconverter.h romanconverter-tests.c
	gcc -c romanconverter-tests.c

digitextractor-tests.o : romanconverter.h digitextractor-tests.c
	gcc -c digitextractor-tests.c

.PHONY : clean
clean :
	rm -f digitextractor-test romanconverter-test kata *.o
