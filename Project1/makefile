# Justin Ventura COSC320
# Project 1: makefile
# Dr. Joseph Anderson

# Command Instructions for usage:
# (1) 'make' creates linearleastsquares exe.
# (2) 'make test' creates test exe for demos.
# (3) 'make clean' to remove non-cpp/h files.

# Flag Variables for Compilation & Linking.
gc = g++ -c -std=c++11
go = g++ -o

# Create the main executable: 'linearleastsquares'
main: main.o matrix.o
	$(go) linearleastsquares main.o matrix.o

# Create the main object file.
main.o: main.cpp matrix.o
	$(gc) main.cpp

# Create the testing executable: 'test'
test: test.o matrix.o
	$(go) test test.o matrix.o

# Create the testing object file.
test.o: test.cpp matrix.o
	$(gc) test.cpp

# Create the matrix object file.
matrix.o: matrix.h matrix.cpp
	$(gc) matrix.cpp

# Clean object files and executables.
clean:
	rm *.o linearleastsquares test