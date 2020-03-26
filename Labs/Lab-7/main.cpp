// Justin Ventura (COSC320-002)
// Lab-7: main.cpp 03/23/20

#include <iostream>
#include <string>
#include "jspace.h"
#include <cmath>
#include <iomanip>
#include <string>

typedef long long int ll;

// Look for collisions.
size_t collisions(ll hash, size_t * arr, size_t len);

// Hash-slinging slasher.
size_t stringhash1(std::string key);

// Hasher 2.
size_t stringhash2(std::string key);

// Hasher 3.
template <typename T>
size_t extracredithash(T * key, size_t bytes);

// Hash-slinger.
size_t hash(size_t key);

// Hash-slasher.
void printHash(size_t hash);

// Stop copying my code, buddy.
int main() {

	std::cout << "--- INTEGER HASHING TESTS ---\n\n";
	
	std::cout << "Prehash integer: 131\n";
	std::cout << "--> hashed 131: \n";
	printHash(hash(131));
	std::cout << "\n";

	std::cout << "Prehash integer: 12390849381\n";
	std::cout << "--> hashed 12390849381: \n";
	printHash(hash(12390849381));
	std::cout << "\n";

	std::cout << "Prehash integer: 1\n";
	std::cout << "--> hashed 1: \n";
	printHash(hash(1));
	std::cout << "\n";

	std::cout << "Prehash integer: 900142069\n";
	std::cout << "--> hashed 900142069: \n";
	printHash(hash(900142069));
	std::cout << "\n";

	std::cout << "Prehash integer: 12390849381 [AGAIN TO SHOW CORRECTNESS]\n";
	std::cout << "--> hashed 12390849381: \n";
	printHash(hash(12390849381));
	std::cout << "\n";

	std::cout << "--- FIRST STRING HASHING TEST ---\n";

	std::string str = "COVID-19 wont stop me from getting my coochie";
	std::cout << "Pre hash: " << str << "\n";
	size_t hashedString = stringhash1(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	str = "Who's Joe?";
	std::cout << "Pre hash: " << str << "\n";
	hashedString = stringhash1(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	str = "Can we get an f in the chat please?";
	std::cout << "Pre hash: " << str << "\n";
	hashedString = stringhash1(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	str = "COVID-19 wont stop me from getting my coochie";
	std::cout << "Pre hash: " << str << "[AGAIN TO SHOW CORRECTNESS]\n";
	hashedString = stringhash1(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	std::cout << "--- TEST REORDERED STRINGS ---\n";

	str = "abcde";
	std::cout << "\nPre hash: " << str << "\n";
	hashedString = stringhash1(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	// Stop copying my code, buddy.
	str = "edcba";
	std::cout << "Pre hash: " << str << "\n";
	hashedString = stringhash1(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	std::cout << "The two strings above are UNIQUE, so their hashes should be as well.\n";

	std::cout << "\n--- SECOND STRING HASHING TEST ---\n";

	str = "Yo if my ex could hop off my D that would be clutch";
	std::cout << "\nPre hash: " << str << "\n";
	hashedString = stringhash2(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	str = "I only do comp sci for the math";
	std::cout << "Pre hash: " << str << "\n";
	hashedString = stringhash2(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	str = "Yo if my ex could hop off my D that would be clutch";
	std::cout << "Pre hash: " << str << "[AGAIN TO SHOW CORRECTNESS]\n";
	hashedString = stringhash2(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	str = "gAmErS rIsE!1!1";
	std::cout << "Pre hash: " << str << "\n";
	hashedString = stringhash2(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	str = "rIsE gAmErS!1!1";
	std::cout << "Pre hash: " << str << "\n";
	hashedString = stringhash2(str);
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	std::cout << "These two strings were put out of order to see if unique hashes.\n";

	std::cout << BACKWHT << FOREBLK "\n --- EXTRA CREDIT CORRECTNESS CHECK --- \n\n";
	std::cout << "My extra credit hash is the same as stringhash1.\n";
	std::cout << "I will hash a string twice and they should have\n";
	std::cout << "the same hash from both functions." << RESET << "\n";

	str = "This is extra credit!";
	std::cout << "Pre hash(str hash): " << str << "\n";
	hashedString = stringhash1(str);
	std::cout << "Post hash(str hash): ";
	printHash(hashedString);
	std::cout << "\n";

	std::cout << "Pre hash(EC hash): " << str << "\n";
	hashedString = extracredithash(str.c_str(), sizeof(str.c_str()));
	std::cout << "Post hash(EC hash): ";
	printHash(hashedString);
	std::cout << "\n";

	std::cout << "^ both of the above should be: 6db83a.\n";
	std::cout << "(Or at least be the same hash; if machine word size varies)\n";

	std::cout << "Template correctness.\n";
	std::cout << "Sos we'll try a random type: float.\n";
	float x = 69.420;
	std::cout << "Pre hash: " << x << "\n";
	hashedString = extracredithash(&x, sizeof(x));
	std::cout << "Post hash: ";
	printHash(hashedString);
	std::cout << "\n";

	return 0;
	
}

// used to play around with hash uniqueness
size_t collisions(ll hash, size_t * arr, size_t len) {

	size_t collisions = 0;

	if (hash == -1) {

		for (size_t i = 0; i < len; i++) {

			for (size_t j = 0; j < len; j++) {

				if (i != j && arr[i] == arr[j]) {

					collisions++;

				}

			}

		}

	}
	else {

		for (size_t i = 0; i < len; i++) {

			if (arr[i] == hash) {

				collisions++;

			}

		}

	}

	return collisions;

}

// Hash-slinging slasher.
size_t stringhash1(std::string key) {

	size_t i = 0;
	size_t sum4hash = 0;
	// Generated from my python script
	const size_t PRIME1 = 1299709;
	const size_t PRIME2 = 15485863;
	while(key[i]) {

		sum4hash += (size_t(key[i]) * (i+1));
		i++;

	}
	// Stop copying my code, buddy.
	return (sum4hash * PRIME1) % PRIME2;

}

size_t stringhash2(std::string key) {

	size_t i = 0;
	size_t sum4hash = 0;
	size_t PRIME = 1746697;
	while(key[i]) {

		sum4hash += (key[i] * PRIME) % (i * i + 1);
		i++;

	}

	return (sum4hash * i) % PRIME;

}

// Hash-slinging slasher EXTRA CREDIT
template <typename T>
size_t extracredithash(T * key, size_t bytes) {

	char key2[bytes];
	memcpy(key2, &key, bytes);
	size_t i = 0;
	size_t sum4hash = 0;
	// Generated from my python script
	const size_t PRIME1 = 1299709;
	const size_t PRIME2 = 15485863;
	while(key[i]) {

		sum4hash += (size_t(key[i]) * (i+1));
		i++;

	}
	// Stop copying my code, buddy.
	return (sum4hash * PRIME1) % PRIME2;

}

// Hash-slinger.
size_t hash(size_t key) {

	// Hard coded as allowed in the prompt.
	const size_t ONE = 1;
	size_t W = ONE << size_t(32);
	size_t p = 19;
	// Prime generated from python script.
	size_t a = 3628273133;

	// Stop copying my code, buddy.
	// size_t ax = a * x;
	// std::cout << ax << "\n";
	size_t ax = a * key;
	size_t axModW = ax &((W) - ONE);
	size_t hash = axModW >> size_t(13);
	return hash;

}

// Hash-slasher.
void printHash(size_t hash) {

	std::cout << FORERED << std::hex << hash << RESET << "\n";

}
