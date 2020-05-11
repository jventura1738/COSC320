# Justin Ventura/Jacob Duncan COSC320
# Project 3: makefile

# Makefile variables
gc = g++ -c -std=c++11 # would be c++20 but not allowed :(
go = g++ -o
binaries = Randomwalk RandomWalk.o Interface.o

RandomWalk: RandomWalk.o Interface.o
	$(go) $(binaries)

RandomWalk.o: RandomWalk.cpp Graph.h Graph.cpp
	$(gc) RandomWalk.cpp

Interface.o: Interface.cpp Interface.h
	$(gc) Interface.cpp

clean:
	rm -rf $(binaries)

# End of makefile
