
kata : main.o
	gcc -o kata main.o

main.o : main.c
	gcc -c main.c

all : clean kata 

.PHONY : clean
clean :
	rm -f kata *.o
