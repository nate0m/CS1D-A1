CC = g++
FLAGS = -std=c++20 -Wall -Werror 

all: a1

a1: algorithms.o a1.cpp
	$(CC) $(FLAGS) a1.cpp -o a1 algorithms.o

algorithms.o: algorithms.cpp algorithms.h
	$(CC) $(FLAGS) -c algorithms.cpp -o algorithms.o

clean: 
	rm a1 *.o

tar:
	tar cf a1.tar Makefile a1.cpp algorithms.cpp algorithms.h
