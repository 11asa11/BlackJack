#pragma once
#include "Dealer.h"
class BlackJack
{
private:
	Dealer dealer;
	std::vector<BJ_Player> players;
	DeckPile deckpile;
public:
	
	BlackJack(std::size_t DealerBank = 1000, std::size_t deckpile = 1);
	void addPlayer(std::size_t bank = 0);
	void players_makeBet();
	// show cards on the table after the first hand
	void showCards();
	void startGame();
};
