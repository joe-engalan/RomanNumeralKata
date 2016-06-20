VPATH = src:tests

CFLAGS = -Isrc

OBJS = romanconverter.o operation.o trim.o calculator.o

TEST_OBJS = romanconverter-tests.o operation-tests.o \
	digitextractor-tests.o patternfinder-tests.o \
	trim-tests.o calculator-tests.o

kata : $(OBJS) main.o
	gcc -o kata main.o $(OBJS)

all : clean test kata

test : $(OBJS) $(TEST_OBJS)
	gcc -Wall $(CFLAGS) -o romanconverter-test romanconverter-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o digitextractor-test digitextractor-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o patternfinder-test patternfinder-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o operation-test operation-tests.o operation.o trim.o -lcheck
	gcc -Wall $(CFLAGS) -o trim-test trim-tests.o trim.o -lcheck
	gcc -Wall $(CFLAGS) -o calculator-test calculator-tests.o $(OBJS) -lcheck
	./romanconverter-test
	./digitextractor-test
	./patternfinder-test
	./trim-test
	./operation-test
	./calculator-test

.PHONY : clean
clean :
	rm -f *-test kata *.o
