# LAB-1 MAKEFILE COSC320-002
# Justin Ventura (Dr. Anderson)

# the variables i always use
gc = g++ -c -std=c++11
go = g++ -o

# 'make' to make executable
main: main.o helpers.o
	$(go) main main.o helpers.o

main.o: main.cpp helpers.h helpers.cpp
	$(gc) main.cpp

helpers.o: helpers.h helpers.cpp
	$(gc) helpers.cpp

# 'make clean' to clean .o's & executables
clean:
	rm *.o main