#include "BJ_Player.h"

BJ_Player::BJ_Player(std::size_t money) : money(money) {}

void BJ_Player::setMoney(std::size_t money) {
	this->money = money;
}

std::size_t BJ_Player::getMoney() {
	return money;
}

void BJ_Player::makeBet(std::size_t bet) {
	try {
		if (static_cast<int>(this->money - bet) < 0) {
            throw "not enough money";
        }
		else {
            this->money -= bet;
            this->bet = bet;
		}
	}
	catch (const char* ex) {
		std::cout << ex << std::endl;
	}
}

std::size_t BJ_Player::getBet() {
	return bet;
}

std::size_t BJ_Player::Win(std::size_t winning) {
	this->money += winning;
	return winning;
}


void BJ_Player::check_ACE_card(Card& card) {
	std::size_t max_Points = 21;
	std::size_t ACE_value_min = 1;
	std::size_t ACE_value_max = 11;
	if (card.getValue() == ACE) {
		if (Points() + ACE_value_max <= max_Points) {
			card.setValue_toACE(ACE_value_max);
		}
		else {
			card.setValue_toACE(ACE_value_min);
		}
	}
}

void BJ_Player::takeCard(Card& card) {
	//check_ACE_card(card);
	player_hand.takeCard(card);
}

void BJ_Player::viewInfo() {
	for (auto& i : player_hand.showInfo()) {
		std::cout << i << std::endl;
	}
}

std::size_t BJ_Player::Points() {
	return player_hand.values();
}

bool BJ_Player::isBlackJack() {
	return Points() == 21;
}

void BJ_Player::clearHand() {
    player_hand.clear();
}

void BJ_Player::Double() {
    if (money < bet) {
        //std::cout<<"money="<<money<<". bet="<<bet<<std::endl;
        throw "Not enough money";
    }
    else {
        money -= bet;
        bet = bet * 2;
    }
}