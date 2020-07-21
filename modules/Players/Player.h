#pragma once
#include <cstddef>
class Player
{
public:
	virtual void makeBet(std::size_t money) = 0;
	virtual std::size_t Win(std::size_t money) = 0;
};

