VPATH = src:tests

CFLAGS = -Isrc

OBJS = main.o romanconverter.o

TEST_OBJS = romanconverter-tests.o \
	digitextractor-tests.o patternfinder-tests.o

kata : $(OBJS)
	gcc -o kata $(OBJS)

all : clean romanconverter-test kata

test : romanconverter.o $(TEST_OBJS)
	gcc -Wall $(CFLAGS) -o romanconverter-test romanconverter-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o digitextractor-test digitextractor-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o patternfinder-test patternfinder-tests.o romanconverter.o -lcheck
	./romanconverter-test
	./digitextractor-test
	./patternfinder-test

.PHONY : clean
clean :
	rm -f patternfinder-test digitextractor-test romanconverter-test kata *.o
