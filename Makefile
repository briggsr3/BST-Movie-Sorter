# Makefile
#flags
CC=g++
CFLAGS= -c -Wall

#building game executable and testcards executable
all: game testcards

#game executable dependencies
game: main.o cards.o
	$(CC) main.o cards.o -o game

#testcards executable dependencies
testcards: cards.o testcards.o
	$(CC) cards.o testcards.o -o testcards

#individual dependencies
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

cards.o: cards.cpp
	$(CC) $(CFLAGS) cards.cpp

testcards.o: testcards.cpp
	$(CC) $(CFLAGS) testcards.cpp

#clean
clean:
	rm -rf *.o game testcards

