#pragma once
#include "Hand.h"
#include "BJ_Player.h"
class Dealer_Hand : public Hand
{
public:
	Dealer_Hand();

	Card& takeCard_fromDeckP(DeckPile& dp);
	void giveCard_toPlayer(BJ_Player& player);

	void takeCard(Card& card) = delete;
};

