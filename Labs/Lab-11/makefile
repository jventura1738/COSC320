# Justin Ventura COSC320 Lab-10

# makefile variables
gc = g++ -c -std=c++11 # would be c++20 but not allowed :(
go = g++ -o

main: main.o
	$(go) main main.o

main.o: main.cpp Graph.h Graph.cpp
	$(gc) main.cpp

clean:
	rm -rf *.o main


# End of makefile