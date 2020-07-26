#include "BlackJack.h"

BlackJack::BlackJack(std::size_t DealerBank, std::size_t deckpile) : dealer(DealerBank), deckpile(deckpile) {
	//dealer.setMoney(DealerBank);
}

void BlackJack::addPlayer(std::size_t bank) {
	players.push_back(BJ_Player(bank));
}

void BlackJack::players_makeBet() {
    int count = 1;
    for (auto& i : players) {
        std::cout << "You are player number: " << count<<". Your money : " << i.getMoney()<<std::endl;
        std::cout << "Make a bet: ";
        std::size_t bet = 0;
        std::cin >> bet;
        i.makeBet(bet);
        count++;
    }
}

void BlackJack::showCards() {
    std::cout<< "SHOW CARD AFTER FIRST HAND"<<std::endl;
    dealer.view_FirstCard();
    int count = 1;
    for (auto& i : players) {
        std::cout << "Player number " << count << " has:"<< std::endl;
        i.viewInfo();
        count++;
    }
}

void BlackJack::startGame() {

	std::size_t num_players = 0;
	std::cout << "Enter number of players: ";
	std::cin >> num_players;
	for (std::size_t i = 1; i <= num_players; i++) {
		std::size_t money = 0;
		std::cout << "Enter amount of money the player number " << i << " has: ";
		std::cin >> money;
		players.emplace_back(money);
	}
    std::cout<<std::endl;

	players_makeBet();

	dealer.Hand_Out_Cards(players, deckpile);
	dealer.Hand_Out_Cards(players, deckpile);

    std::cout << std::endl << std::endl;

	showCards();

	int count = 1;

	std::cout << std::endl << std::endl;

	if(dealer.isBlackJack()) {
        dealer.Distribute_Winnings(players);
        for (auto& i : players) {
            dealer.Win(i.getBet());
        }
	}
    else {
        for (auto &i : players) {
            std::cout << "----------YOU ARE PLAYER----------" << std::endl;
            std::cout << "You are player number: " << count << std::endl;
            std::cout << "Your cards: " << std::endl;
            i.viewInfo();
            if (i.isBlackJack()) {
                std::cout << "Congratulations - BlackJack!" << std::endl;
            } else {
                int flag = 0;
                std::cout << "Do you want to take another card? If YES press 1, else 0: ";
                std::cin >> flag;
                while (flag == 1) {
                    dealer.giveOneMore_Card(i, deckpile);
                    std::cout << "Your cards: " << std::endl;
                    i.viewInfo();
                    std::cout << "Number of cards: " << deckpile.size() << std::endl;
                    std::cout << "Do you want to take another card? If YES press 1, else 0: ";
                    std::cin >> flag;
                }
            }
            count++;
        }


        std::cout << std::endl << std::endl;
        std::cout << "----------YOU ARE DEALER----------" << std::endl;
        std::cout << "Your money: " << dealer.getMoney() << std::endl;
        std::cout << "Your cards: " << std::endl;
        dealer.viewInfo();
        if (dealer.isBlackJack()) {
            std::cout << "Congratulations - BlackJack!" << std::endl;
        } else {
            int flag = 0;
            std::cout << "Do you want to take another card? If YES press 1, else 0: ";
            std::cin >> flag;
            while (flag == 1) {
                dealer.giveOneMore_Card(dealer, deckpile);
                std::cout << "Your cards: " << std::endl;
                dealer.viewInfo();
                std::cout << "Number of cards: " << deckpile.size() << std::endl;
                std::cout << "Do you want to take another card? If YES press 1, else 0: ";
                std::cin >> flag;
            }
        }


        /*std::cout << std::endl << std::endl;
        std::cout << "----------COMPARING CARDS----------" << std::endl;*/
        dealer.Distribute_Winnings(players);
    }
    std::cout << std::endl << std::endl;
    std::cout << "----------COMPARING CARDS----------" << std::endl;
    count = 1;
	for (auto& i : players) {
		std::cout << "Player number " << count << " has money - " << i.getMoney() << std::endl;
		count++;
	}
	std::cout << "Dealer has money - " << dealer.getMoney();
}