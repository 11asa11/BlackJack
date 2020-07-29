#pragma once
#include "Dealer_Hand.h"

class Dealer : public BJ_Player
{
private:
	Dealer_Hand dealer_hand;
public:
	Dealer();
	Dealer(std::size_t bank);

	void Hand_Out_Cards(std::vector<BJ_Player>& players, DeckPile& dp);

	void giveOneMore_Card(BJ_Player& player, DeckPile& dp);
	 
	void Distribute_Winnings(std::vector<BJ_Player>& players);

	void view_FirstCard();

	void Play(DeckPile&);

	void Lose(std::size_t bet);

	void Double() = delete;

};
