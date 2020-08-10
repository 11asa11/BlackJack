#pragma once
#include <cstddef>
#include <string>
#include <map>

enum Ranks {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE 
};

enum Suits {
	HEART,
	DIAMOND,
	CLUB,
	SPADE
};



class Card
{
private:
	std::map<Ranks, std::size_t> rank_val{
	{TWO,2}, {THREE,3},
	{FOUR,4}, {FIVE,5},
	{SIX,6}, {SEVEN,7},
	{EIGHT,8}, {NINE,9},
	{TEN,10}, {JACK,10},
	{QUEEN,10}, {KING,10}, {ACE,11}
	};
	Ranks rank;
	Suits suit;
public:

	Card();
	Card(Suits suit, Ranks rank);
	Card(const Card& card);
	~Card();
	std::string Info();
	void setValue_toACE(std::size_t val);
	std::size_t getValue_Info();
	std::string getSuit_Info();
	Ranks getValue();
	Suits getSuit();
};