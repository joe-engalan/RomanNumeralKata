VPATH = src:tests

CFLAGS = -Isrc

OBJS = romanconverter.o operation.o trim.o

TEST_OBJS = romanconverter-tests.o operation-tests.o \
	digitextractor-tests.o patternfinder-tests.o \
	trim-tests.o

kata : $(OBJS)
	gcc -o kata $(OBJS)

all : clean romanconverter-test kata

test : $(OBJS) $(TEST_OBJS)
	gcc -Wall $(CFLAGS) -o romanconverter-test romanconverter-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o digitextractor-test digitextractor-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o patternfinder-test patternfinder-tests.o romanconverter.o -lcheck
	gcc -Wall $(CFLAGS) -o operation-test operation-tests.o operation.o trim.o -lcheck
	gcc -Wall $(CFLAGS) -o trim-test trim-tests.o trim.o -lcheck
	./romanconverter-test
	./digitextractor-test
	./patternfinder-test
	./trim-test
	./operation-test

.PHONY : clean
clean :
	rm -f *-test kata *.o
