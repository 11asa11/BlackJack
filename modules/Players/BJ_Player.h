#pragma once
#include "Player.h"
#include "Hand.h"
#include <iostream>


class BJ_Player : public Player
{
private:
    std::size_t money;
protected:
	Hand player_hand;
	std::size_t bet = 0;
public:
	BJ_Player(std::size_t money = 0);

	void setMoney(std::size_t money);
	std::size_t getMoney();

	void makeBet(std::size_t bet) final;
	std::size_t getBet();

	std::size_t Win(std::size_t bet) final;
	//void Lose(std::size_t bet);

	void check_ACE_card(Card& card);
	void takeCard(Card& card);

	// Info about cards
	void viewInfo();
	std::size_t Points();
	bool isBlackJack();

    //clear your hand of cards
	void clearHand();

	void Double();
};
