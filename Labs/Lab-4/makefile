# Justin Ventura, 2/24/20
# COSC320 Lab-4 Makefile
# Dr. Joseph Anderson

# makefile variables
gc = g++ -c -std=c++11 -Wall # would be c++20 but not allowed :(
go = g++ -o

main: main.o matrix.o timer.o
	$(go) main main.o matrix.o

main.o: main.cpp matrix.o timer.o
	$(gc) main.cpp

matrix.o: matrix.cpp matrix.h
	$(gc) matrix.cpp

timer.o: timer.h timer.cpp
	$(gc) timer.cpp

# run make memcheck for memory checking.
memcheck:
	valgrind --leak-check=yes ./main

clean:
	rm *.o main