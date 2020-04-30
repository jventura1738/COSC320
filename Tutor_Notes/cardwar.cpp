// Justin Ventura Tutor Notes
#include <iostream>
#include <random>
#include <time.h>

// States for the game.
enum STATE {P1WIN = 0, P2WIN, DRAW, NIL};

// char arrays for creating deck.
char VALUES [] = {'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
char SUITS [] = {'S','C','D','H'};

// card struct.
struct Card {

	// example: 3D, AS, 5K etc.
	char value;
	char suit;

	// default constructor.
	Card() { 

		this->value = '*';
		this->suit = '*';

	}

	// constructor to make a card with
	// the given value (v) and suit (s).
	Card(char v, char s) {

		this->value = v;
		this->suit = s;

	}

	int getValue() {

		return toValue(this->value);

	}

	int toValue(char & c) {

		switch(c) {

			case 'A': return 1; break;
			case '2': return 2; break;
			case '3': return 3; break;
			case '4': return 4; break;
			case '5': return 5; break;
			case '6': return 6; break;
			case '7': return 7; break;
			case '8': return 8; break;
			case '9': return 9; break;
			case '0': return 10; break;
			case 'J': return 11; break;
			case 'Q': return 12; break;
			case 'K': return 13; break;

		}

		return -1;

	}

	Card nullcard() {

		Card nullcard;
		return nullcard;

	}

	bool isnullcard() {

		if (this->getValue() == -1) {

			return true;

		}

		return false;

	}

};

struct pdeck {
public:
	std::vector<Card> hand;
	
	void receiveCard(Card & card) {

		this->hand.insert(this->hand.begin(), card);

	}

	Card playCard() {

		if (this->hand.empty()) {

			Card c;
			c = c.nullcard();
			return c;

		}

		Card temp = this->hand.back();
		this->hand.pop_back();
		return temp;

	}

};

// deck struct.
struct Deck {
public:
	// keeps track of top index.
	int topindex;

	// the card on top of the deck.
	Card top;

	// the actual deck (array of cards).
	Card * underlying_deck;

	// this constructor will build the deck.
	Deck() {

		// dynamically allocated heap memory for 
		// the deck of cards. (array)
		this->underlying_deck = new Card[52];

		// keep track of which card is added.
		int index = 0;

		// each suit
		for (int i = 0; i < 4; i++) {

			// each value
			for (int j = 0; j < 13; j++) {

				this->underlying_deck[index++] = Card(VALUES[j], SUITS[i]);

			}

		}

		// make the first card the top.
		this->top = this->underlying_deck[0];
		this->topindex = 0;

	}

	// destructor. frees dynamically allocated
	// memory.
	~Deck() {

		delete [] this->underlying_deck;

	}

	// this returns the top of the deck,
	// then makes the next topmost become
	// the new top.
	Card & pullFromTop() {

		if (this->topindex >= 52) {

			std::cout << "Empty pile!\n";
			throw std::string("ERROR.");

		}

		return this->underlying_deck[this->topindex++];

	}


};

// Shuffle a given array of cards.
void shuffleDeck(Card *);

void playGame(struct pdeck & player1, struct pdeck & player2);

int main() {
	
	Deck d;
	shuffleDeck(d.underlying_deck);
	pdeck p1, p2;
	int i = 0;
	while (i < 26) {

		p1.receiveCard(d.pullFromTop());
		p2.receiveCard(d.pullFromTop());
		i++;

	}
	playGame(p1, p2);

	return 0;
}

void shuffleDeck(Card * array) {

	srand(time(0));
	for (int i = 0; i < 1000; i++) {

		int num1 = rand() % 52;
		int num2 = rand() % 52;
		std::swap(array[num1], array[num2]);

	}

}

void playGame(struct pdeck & player1, struct pdeck & player2) {

	bool play_game = true;
	STATE gamestate = NIL;

	std::vector<Card> p1moves;
	std::vector<Card> p2moves;

	while(play_game) {

		if (gamestate != DRAW) {

			p1moves.push_back(player1.playCard());
			p2moves.push_back(player2.playCard());

		}
		else {

			p1moves.push_back(player1.playCard());
			p2moves.push_back(player2.playCard());

			p1moves.push_back(player1.playCard());
			p2moves.push_back(player2.playCard());

		}

		if (p1moves.back().isnullcard()) {

			std::cout << "Player 1 loses game!\n";
			play_game = false;

		}
		else if (p2moves.back().isnullcard()) {

			std::cout << "Player 2 loses game!\n";
			play_game = false;

		}

		if (p1moves.back().getValue() > p2moves.back().getValue()) {

			gamestate = P1WIN;

		}
		else if (p2moves.back().getValue() > p1moves.back().getValue()) {

			gamestate = P2WIN;

		}
		else {

			gamestate = DRAW;

		}


		if (gamestate == P1WIN) {

			std::cout << "Player 1 win!\n";

			for (auto iter = p1moves.begin(); iter != p1moves.end(); iter++) {

				player1.receiveCard(*iter);

			}
			for (auto iter = p2moves.begin(); iter != p2moves.end(); iter++) {

				player1.receiveCard(*iter);

			}

		}
		else if (gamestate == P2WIN) {

			std::cout << "Player 2 win!\n";

			for (auto iter = p1moves.begin(); iter != p1moves.end(); iter++) {

				player2.receiveCard(*iter);

			}
			for (auto iter = p2moves.begin(); iter != p2moves.end(); iter++) {

				player2.receiveCard(*iter);

			}

		}
		else {

			std::cout << "Draw!\n";

		}

	}

}
