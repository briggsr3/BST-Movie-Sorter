# Makefile
#flags
CC=g++
CFLAGS= -c -Wall

#building game executable and testcards executable
all: runMovies testTarget


#autorun
tests:
	./testTarget


#executable dependencies
runMovies: main.o movies.o utility.o
	$(CC) main.o movies.o -o runMovies


testTarget: tests.o movies.o utility.o
	$(CC) tests.o movies.o utility.o -o testTarget


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
	rm -rf *.o runMovies testTarget
