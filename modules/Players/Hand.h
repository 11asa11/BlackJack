#pragma once
#include <vector>
#include "DeckPile.h"
class Hand
{
protected:
	std::vector<Card> h_cards;
public:
	Hand();

	void takeCard(Card& card);
	std::vector<std::string> showInfo();
	std::size_t values();
	std::size_t number_cards();
};
