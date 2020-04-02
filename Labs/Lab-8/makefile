# Justin Ventura COSC320 Lab-8

# makefile variables
gc = g++ -c -std=c++11 # would be c++20 but not allowed :(
go = g++ -o

main: main.o BST.o
	$(go) main main.o BST.o

BST.o: BST.h BST.cpp
	$(gc) BST.cpp

clean:
	rm -rf *.o main
