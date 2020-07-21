#include "Card.h"

Card::Card() {}

Card::Card(Suits suit, Ranks rank) : suit(suit), rank(rank) {}

Card::Card(const Card& card) {
	rank = card.rank;
	suit = card.suit;
	rank_val.find(rank)->second = card.rank_val.find(rank)->second;
}

Card::~Card() {}

std::string Card::Info() {
	std::string str = "";
	switch (rank) {
	case ACE:  str += "ACE"; break;
	case TWO:  str += "TWO"; break;
	case THREE:  str += "THREE"; break;
	case FOUR:  str += "FOUR"; break;
	case FIVE:  str += "FIVE"; break;
	case SIX:  str += "SIX"; break;
	case SEVEN:  str += "SEVEN"; break;
	case EIGHT:  str += "EIGHT"; break;
	case NINE:  str += "NINE"; break;
	case TEN:  str += "TEN"; break;
	case JACK:  str += "JACK"; break;
	case QUEEN:  str += "QUEEN"; break;
	case KING:  str += "KING"; break;
	}

	str += " - " + std::to_string(rank_val.find(rank)->second);
	str += ". " + getSuit_Info();
	return str;
}

void Card::setValue_toACE(std::size_t val) {
	rank_val[rank] = val;
}

std::size_t Card::getValue_Info() {
	return rank_val.find(rank)->second;
}

std::string Card::getSuit_Info() {
	if (suit == 0) {
		return "HEART";
	}
	else if (suit == 1) {
		return "DIAMOND";
	}
	else if (suit == 2) {
		return "CLUB";
	}
	else {
		return "SPADE";
	}
}

Ranks Card::getValue() {
	return rank;
}
Suits Card::getSuit() {
	return suit;
}