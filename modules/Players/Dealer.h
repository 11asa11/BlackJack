#pragma once
#include "Dealer_Hand.h"

class Dealer : public BJ_Player
{
private:
	Dealer_Hand dealer_hand;
	using BJ_Player:: Win;
    using BJ_Player::makeBet;
public:
	Dealer();
	Dealer(std::size_t bank) = delete;

	void Hand_Out_Cards(std::vector<BJ_Player>& players, DeckPile& dp);

	void giveOneMore_Card(BJ_Player& player, DeckPile& dp);
	 
	void Distribute_Winnings(std::vector<BJ_Player>& players);

	void view_FirstCard();

	void Play(DeckPile&);

	void Lose(std::size_t bet) = delete;
    //std::size_t Win(std::size_t bet) = delete;
	void Double() = delete;
    void setMoney(std::size_t money) = delete;
    std::size_t getMoney() = delete;
    //void makeBet(std::size_t bet) = delete;
    std::size_t getBet() = delete;

};
