# Justin Ventura COSC320
# Project 1: makefile

gc = g++ -c -std=c++11
go = g++ -o

test: test.o matrix.o
	$(go) test test.o matrix.o

test.o: test.cpp matrix.o
	$(gc) test.cpp

main: main.o matrix.o
	$(go) main main.o matrix.o

main.o: main.cpp matrix.o
	$(gc) main.cpp

matrix.o: matrix.h matrix.cpp
	$(gc) matrix.cpp

clean:
	rm *.o main test