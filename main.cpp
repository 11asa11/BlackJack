#include <iostream>
#include "BlackJack.h"

int main()
{
    setlocale(LC_ALL, "rus");
    BlackJack bj(100);
    bj.startGame();
    return 0;
}
