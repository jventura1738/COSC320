# Justin Ventura COSC320 Lab-8

# makefile variables
gc = g++ -c -std=c++11 # would be c++20 but not allowed :(
go = g++ -o

main: main.o jspace.h jspace.cpp
	$(go) main main.o

main.o: main.cpp
	$(gc) main.cpp

clean:
	rm -rf *.o main
