# Justin Ventura
# Makefile for QuickSort

go = g++ -o
gc = g++ -c -std=c++11

main: main.o
	$(go) main main.o

main.o: main.cpp
	$(gc) main.cpp

memcheck:
	valgrind --leak-check=yes ./main

clean:
	rm main *.o
