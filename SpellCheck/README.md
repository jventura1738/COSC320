# Justin's SpellCheck with Hashing.

by Justin Ventura (Dr. Joe Anderson)

2/3 EXTRA CREDIT COMPLETED.

## Specifications.

This Project uses Hashing with chaining in order to quickly be able to check for mispelled words, then uses a few techniques in order to come up with suggestions for mispelled words (based on the dictionary .txt file).  Upon loading, the text file words are loaded into a dynamic hash table with a hash which evenly distributes for fast access.  Then the user may enter a sentence, the program highlights incorrect words and shows suggestions within 1-2 edit distances.  THe user may choose to add those mispelled words to the dictionary file if they believe the words are missing, or choose to add their own words.


The following implementations were included in order to go through with this whole process of the Spell Checker:

- A doubly linked list 'chain' for the hash table.
- A Hash Table with a solid hashing function.
- Multiple functions which work in unison in order to check for words which need suggestion, find the suggestions, print the suggestions, then prompt the user if they wish to use the suggestions or not.

## README:

Instructions to run the programs (also located in makefile):
- To create the object files & executables: 'make'
- To run memory checks for the main: 'make memcheck'.  The latter will run with english.txt by default.  If you wish to use your own files, simply use your own commands such as: 'valgrind ./spellcheck <filename>' or 'valgrind ./iomodel <file>'
- NOTE: you may only do one file argument.
  
### Hashing Description & Tests:

The hashing function I made uses prime numbers which I generated from my python script.  The method I used for hashing was made by me and ensured that small changes in a word resulted in a vastly different hash.  This also means that the string 'abc' and 'cba' have unique hashes.

### EXTRA CREDIT! (15pts)

- I have implemented the highlight for showing mispelled words (5pts).
- I also implemented a feature where the user can choose to add the mispelled words to the dictionary, or add their own (ie. pick from the suggestion list).  
