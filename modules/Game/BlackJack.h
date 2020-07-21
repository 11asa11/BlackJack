#pragma once
#include "Dealer.h"
class BlackJack
{
private:
	Dealer dealer;
	std::vector<BJ_Player> players;
	DeckPile deckpile;
public:
	
	BlackJack(std::size_t DealerBank, std::size_t deckpile = 1);
	void addPlayer(std::size_t bank = 0);
	void startGame();
};
