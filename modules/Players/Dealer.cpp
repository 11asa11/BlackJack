#include "Dealer.h"

Dealer::Dealer() {}

Dealer::Dealer(std::size_t bank) : BJ_Player(bank) {}

void Dealer::Hand_Out_Cards(std::vector<BJ_Player>& players, DeckPile& dp) {
	for (auto& i : players) {
		giveOneMore_Card(i, dp);
	}
	giveOneMore_Card(*this, dp);
}

void Dealer::giveOneMore_Card(BJ_Player& player, DeckPile& dp) {
	Card& card = dealer_hand.takeCard_fromDeckP(dp);
	player.check_ACE_card(card);
	dealer_hand.giveCard_toPlayer(player);
}

void Dealer::Distribute_Winnings(std::vector<BJ_Player>& players) {
	double coeff_win = 1.5;
	std::size_t d_points = this->Points();
	for (auto& i : players) {
		std::size_t p_points = i.Points();

		if (p_points > 21 && d_points <= 21) {
			this->Win(i.getBet());
		}
		else if (p_points <= 21 && d_points > 21) {
			i.Win(i.getBet() * coeff_win);
			this->Lose(i.getBet());
		}
		else if (p_points <= 21 && d_points <=21) {
			if (p_points > d_points) {
				i.Win(i.getBet() * coeff_win);
				this->Lose(i.getBet());
			}
			else if (p_points < d_points) {
				this->Win(i.getBet());
			}
			else {
				i.Win(i.getBet());
			}
		}
		else if (p_points > 21 && d_points > 21) {
			this->Win(i.getBet()); // or nothing
		}
	}
}

void Dealer::view_FirstCard() {
    std::cout << "The 1st card of dealer: "<< player_hand.showInfo().front() << std::endl;
}

void Dealer::Lose(std::size_t lose) {
	money -= lose;
}