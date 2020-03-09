# Justin Ventura COSC320
# Project 1 Makefile 
# IOModel (Dr. Anderson)

# ========== INSTRUCTIONS FOR IOMODEL ===========
#                                               |
#                --- driver ---                 |
#                                               |
# Command to build demo: 'make driver'          |
# Command to run driver: './driver'             |
# Memory check driver: 'make m_driver'          |
#                                               |
#                --- IOModel ---                |
#                                               |
# Command to build IOModel: 'make iomodel'.     |
# Command to run IOmodel: './iomodel <filename>'|
# Memory check IOModel: valgrind --leak-check   |
#                                               |
#                 --- Clean ---                 |
#                                               |
# Command to clean: 'make clean'                |
#                                               |
# ===============================================

# Makefile variables.
gc = g++ -c -std=c++11
go = g++ -o

# Creates executable for driver test.
driver: driver.o matrix.o
	$(go) driver matrix.o driver.o

# Creates driver object file.
driver.o: driver.cpp matrix.cpp jspace.h jspace.cpp
	$(gc) driver.cpp matrix.cpp

# Memory checking for driver.
m_driver:
	valgrind --leak-check=yes --track-origins=yes ./driver

# Clean object files and executables.
clean:
	rm *.o driver 
