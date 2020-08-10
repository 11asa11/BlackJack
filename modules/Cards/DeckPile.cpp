#include "DeckPile.h"

DeckPile::DeckPile() {
	deckpile.resize(0);
}
DeckPile::DeckPile(std::size_t count) {
	loadDeckPile(count);
	shuffleDeckPile();
}
void DeckPile::loadDeckPile(std::size_t count) {
	std::vector<Deck> decks(count);
	const std::size_t def_deck_size = 52;
	deckpile.resize(def_deck_size * count);
	for (std::size_t i = 0; i < count; i++) {
		std::move_backward(decks[i].appeal_toDeck().begin(), decks[i].appeal_toDeck().end(), deckpile.begin() + (i + 1) * def_deck_size);
	}
}
void DeckPile::shuffleDeckPile() {
	unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());
	std::default_random_engine e(seed);
	std::shuffle(deckpile.begin(), deckpile.end(), e);
}

Card DeckPile::giveCard_toHand() {
	Card card = deckpile[deckpile.size() - 1];
	deckpile.pop_back();
	return card;
}

std::vector<Card>& DeckPile::appeal_toDeckPile() {
	return deckpile;
}
std::size_t DeckPile::size() {
	return deckpile.size();
}