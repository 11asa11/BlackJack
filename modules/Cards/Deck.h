#pragma once
#include "Card.h"
#include <vector>

class Deck
{
private:
	std::vector<Card> deck;
public:
	Deck();

	void loadSuit(Suits s);
	void loadDeck();
	std::vector<Card>& appeal_toDeck();
};
