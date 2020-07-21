#include "Deck.h"

Deck::Deck() {
	loadDeck();
}

void Deck::loadSuit(Suits s) {
	Ranks rank;
	for (std::size_t i = 1; i <= 13; i++) {
		switch (i) {
		case 1:  rank = TWO; break;
		case 2:  rank = THREE; break;
		case 3:  rank = FOUR; break;
		case 4:  rank = FIVE; break;
		case 5:  rank = SIX; break;
		case 6:  rank = SEVEN; break;
		case 7:  rank = EIGHT; break;
		case 8:  rank = NINE; break;
		case 9:  rank = TEN; break;
		case 10:  rank = JACK; break;
		case 11:  rank = QUEEN; break;
		case 12:  rank = KING; break;
		case 13:  rank = ACE;
		}
		deck.emplace_back(s, rank);
	}
}

void Deck::loadDeck() {
	Suits suit;
	for (std::size_t i = 1; i <= 4; i++) {
		switch (i) {
		case 1:  suit = HEART; break;
		case 2:  suit = DIAMOND; break;
		case 3:  suit = CLUB; break;
		case 4:  suit = SPADE;
		}
		loadSuit(suit);
	}
}

std::vector<Card>& Deck::appeal_toDeck() {
	return deck;
}