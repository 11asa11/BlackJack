#include <iostream>
#include "BlackJack.h"

int main()
{
    setlocale(LC_ALL, "rus");
    std::cout<<"Enter deckpile size:";
    std::size_t dp_size;
    std::cin>>dp_size;
    BlackJack bj(dp_size);
    bj.startGame();
    return 0;
}
