# Justin Ventura COSC320
# Project 2 Makefile 
# Spell Check (Dr. Anderson)

# ======= INSTRUCTIONS FOR SPELL CHECK ==========
#                                               |
#              --- MAKE & RUN ---               |
#                                               |
# Command to make: 'make'                       |
# Comamnd to run: './spellcheck'                |
#                                               |
#             --- MEMORY CHECK ---              |
#                                               |
# Command for memory checking:                  |
# --> 'make memcheck'                           |
#                                               |
#                --- Clean ---                  |
#                                               |
# Command to clean: 'make clean'                |
#                                               |
# ===============================================

# Makefile variables.
gc = g++ -c -std=c++11
go = g++ -o
memchk = 	valgrind --leak-check=yes --track-origins=yes
binaries = spellcheck

# Link the main object file to create executable.
spellcheck: main.o chain.o
	$(go) spellcheck main.o chain.o

# Make the main object file.
main.o: main.cpp jspace.h jspace.cpp
	$(gc) main.cpp

# Make the chain object file.
chain.o: chain.h chain.cpp
	$(gc) chain.cpp

memcheck: spellcheck
	$(memchk) ./spellcheck

# Clean object files and executables.
clean:
	rm -f *.o $(binaries)
