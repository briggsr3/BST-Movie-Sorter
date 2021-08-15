# Makefile
#flags
CC=g++
CFLAGS= -c -Wall

#building game executable and testcards executable
all: runMovies testTarget tests

#game executable dependencies
runMovies: main.o movies.o utility.o
	$(CC) main.o cards.o -o runMovies

#testcards executable dependencies
testTarget: movies.o utility.o tests.o
	$(CC) movies.o utility.o tests.o -o testTarget


tests: testTarget
	./testTarget


#individual dependencies
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

movies.o: movies.cpp
	$(CC) $(CFLAGS) movies.cpp

tests.o: tests.cpp
	$(CC) $(CFLAGS) tests.cpp

utility.o: utility.cpp
	$(CC) $(CFLAGS) utility.cpp

#clean
clean:
	rm -rf *.o runMovies testTarget tests
