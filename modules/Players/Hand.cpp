#include "Hand.h"

Hand::Hand() {}

void Hand::takeCard(Card& card) {
	h_cards.push_back(card);
}

std::vector<std::string> Hand::showInfo() {
	std::vector<std::string> vec;
	for (auto& i : h_cards) {
		vec.push_back(i.Info());
	}
	return vec;
}

std::size_t Hand::values() {
	std::size_t val = 0;
	for (auto& i : h_cards) {
		val += i.getValue_Info();
	}
	return val;
}

std::size_t Hand::number_cards() {
	return h_cards.size();
}