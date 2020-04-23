// COSC120 Justin Ventura.
// Tutor notes.
#include <iostream>

// char arrays for creating deck.
char VALUES [] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
char SUITS [] = {'S','C','D','H'};

// card struct.
struct card {

	// example: 3D, AS, 5K etc.
	char value;
	char suit;

	// default constructor.
	card() { 

		this->value = '*';
		this->suit = '*';

	}

	// constructor to make a card with
	// the given value (v) and suit (s).
	card(char v, char s) {

		this->value = v;
		this->suit = s;

	}

};

// deck struct.
struct deck {
public:
	// keeps track of top index.
	int topindex;

	// the card on top of the deck.
	card top;

	// the actual deck (array of cards).
	card * underlying_deck;

	// this constructor will build the deck.
	deck() {

		// dynamically allocated heap memory for 
		// the deck of cards. (array)
		this->underlying_deck = new card[52];

		// keep track of which card is added.
		int index = 0;

		// each suit
		for (int i = 0; i < 4; i++) {

			// each value
			for (int j = 0; j < 13; j++) {

				this->underlying_deck[index++] = card(VALUES[j], SUITS[i]);

			}

		}

		// make the first card the top.
		this->top = this->underlying_deck[0];
		this->topindex = 0;

	}

	// destructor. frees dynamically allocated
	// memory.
	~deck() {

		delete [] this->underlying_deck;

	}

	// this returns the top of the deck,
	// then makes the next topmost become
	// the new top.
	card pullFromTop() {

		// TODO: check for errors (if pile is empty)

		return this->underlying_deck[this->topindex++];

	}


};

// hand struct.
struct hand {
public:

	// keeps track of hand size.
	int handsize;

	// current hand.
	card * currhand;

	// constructor to allocate 5 spaces for
	// cards.
	hand() {

		this->currhand = new card[5];
		this->handsize = 0;

	}

	// destructor;
	~hand() {

		delete [] this->currhand;

	}

	// adds a given card to the hand, will
	// check for duplicate card & exceeding
	// the hand limit.
	void addToHand(struct card c) {

		// TODO: make sure the hand limit is not
		// exceeded. and make sure that there are
		// no duplicates.

		this->currhand[this->handsize++] = c;

	}


};

// prints a given card.
void printcard(struct card);

// TODO: add a function to print the
// hand.
void printhand(struct hand);

int main () {

	deck d;

	hand justinshand;
	hand kyleshand;

	justinshand.addToHand(d.pullFromTop());
	kyleshand.addToHand(d.pullFromTop());

	printcard(justinshand.currhand[0]);
	printcard(kyleshand.currhand[0]);

	return 0;

}

void printcard(struct card c) {

	if (c.value == '0') {

		std::cout << 10 << c.suit << "\n";
		return;

	}

	std::cout << c.value << c.suit << "\n";

}