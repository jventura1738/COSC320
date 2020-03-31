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
data1 = english.txt

# Link the main object file to create executable.
spellcheck: main.o chain.o
	$(go) spellcheck main.o chain.o Dictionary.o timer.o

# Make the main object file.
main.o: main.cpp jspace.h jspace.cpp Dictionary.o timer.o
	$(gc) main.cpp

# Make the Dictionary object file.
Dictionary.o: Dictionary.h Dictionary.cpp chain.o
	$(gc) Dictionary.cpp

# Make the chain object file.
chain.o: chain.h chain.cpp
	$(gc) chain.cpp

timer.o: timer.h timer.cpp
	$(gc) timer.cpp

memcheck: spellcheck
	$(memchk) ./$(binaries) $(data1)

# Clean object files and executables.
clean:
	rm -f *.o $(binaries)
