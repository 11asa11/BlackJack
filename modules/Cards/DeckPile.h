#pragma once
#include "Deck.h"
#include <random>
#include <chrono>
#include <algorithm>
class DeckPile
{
private:
	std::vector<Card> deckpile;
public:
	DeckPile();
	DeckPile(std::size_t count);
	void loadDeckPile(std::size_t count);
	void shuffleDeckPile();
	Card giveCard_toHand();
	std::vector<Card>& appeal_toDeckPile();
	std::size_t size();
};
