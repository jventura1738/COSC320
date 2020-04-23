// Justin Ventura Tutor Notes COSC120

// Determines if a given shuffle of
// cards is a derangement.

#include <iostream>
#include <time.h>
#include <random>
#define RED   "\x1B[31m" // Red Color
#define RESET "\x1B[0m"  // Reset color.

int DECKSIZE = 52;

struct Card {
private:
	int value;
	int suit;

public:
	Card() { value = -1; suit = -1; }
	Card(int s, int v) : suit(s), value(v) { }

	std::string getCard() {

		std::string VAL, SUIT;
		switch(this->value) {

			case 1: VAL = "A"; break;
			case 2: VAL = "2"; break;
			case 3: VAL = "3"; break;
			case 4: VAL = "4"; break;
			case 5: VAL = "5"; break;
			case 6: VAL = "6"; break;
			case 7: VAL = "7"; break;
			case 8: VAL = "8"; break;
			case 9: VAL = "9"; break;
			case 10: VAL = "10"; break;
			case 11: VAL = "J"; break;
			case 12: VAL = "Q"; break;
			case 13: VAL = "K"; break;

		} 
		switch(this->suit) {

			case 1: SUIT = "S"; break;
			case 2: SUIT = "H"; break;
			case 3: SUIT = "C"; break;
			case 4: SUIT = "D"; break;

		}

		return VAL + SUIT;

	}

};

// Initializes a deck of cards.
struct Card * initializeDeck();

// Shuffle a given array of cards.
void shuffleDeck(struct Card *);

// Print an array of cards in order.
void printCards(struct Card *);

// Takes an array of cards, and checks if it is a
// derrangement or not.
bool isDerangement(struct Card *, struct Card *);

// Print the places in which there is a derangement
// violation in red.
void showResult(struct Card *, struct Card *);

int main() {

	// Testing program.

	Card * deck1 = initializeDeck();
	Card * deck2 = initializeDeck();
	shuffleDeck(deck2);

	printCards(deck1);
	printCards(deck2);
	std::cout << "\n<->\n";

	bool result = isDerangement(deck1, deck2);
	if (result) {

		std::cout << "\nThis is a derangement!\n";
		showResult(deck1, deck2);

	}
	else {

		std::cout << "\nThis is not a derangement.\n";
		showResult(deck1, deck2);

	}

	delete [] deck1;
	delete [] deck2;

	return 0;
}

struct Card * initializeDeck() {

	Card * deck = new Card[52];

	int index = 0;
	for (int i = 1; i <= 4; i++) {

		for (int j = 1; j <= 13; j++) {

			deck[index++] = Card(i, j);

		}

	}

	return deck;

}

void shuffleDeck(struct Card * deck) {

	srand(time(0));
	for (int i = 0; i < 1000; i++) {

		int num1 = rand() % 52;
		int num2 = rand() % 52;
		std::swap(deck[num1], deck[num2]);

	}

}

void printCards(struct Card * deck) {

	for (int i = 0; i < DECKSIZE; i++) {

		std::cout << deck[i].getCard() << " ";

	}

	std::cout << "\n";

}

bool isDerangement(struct Card * deck1, struct Card * deck2) {

	for (int i = 0; i < DECKSIZE; i++) {

		if (deck1[i].getCard() == deck2[i].getCard()) {

			return false;

		}

	}

	return true;

}

void showResult(struct Card * deck1, struct Card * deck2) {

	for (int i = 0; i < DECKSIZE; i++) {

		if (deck1[i].getCard() == deck2[i].getCard()) {

			std::cout << RED << deck1[i].getCard() << RESET << " ";

		}
		else {

			std::cout << deck1[i].getCard() << " ";

		}

	}

	std::cout << "\n";

	for (int i = 0; i < DECKSIZE; i++) {

		if (deck1[i].getCard() == deck2[i].getCard()) {

			std::cout << RED << deck2[i].getCard() << RESET << " ";

		}
		else {

			std::cout << deck2[i].getCard() << " ";

		}

	}

	std::cout << "\n";

}

// End of derangement.cpp