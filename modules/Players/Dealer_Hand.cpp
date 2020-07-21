#include "Dealer_Hand.h"

Dealer_Hand::Dealer_Hand() {}

Card& Dealer_Hand::takeCard_fromDeckP(DeckPile& dp) {
	//Card card = dp.giveCard_toHand();
	h_cards.push_back(dp.giveCard_toHand());
	//return h_cards[h_cards.size() - 1];
	return h_cards.back();

}

void Dealer_Hand::giveCard_toPlayer(BJ_Player& player) {
	Card card = h_cards[h_cards.size() - 1];
	h_cards.pop_back();
	player.takeCard(card);
}
