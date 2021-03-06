#include "BlackJack.h"

//BlackJack::BlackJack(std::size_t DealerBank, std::size_t deckpile) : dealer(DealerBank), deckpile(deckpile) {}
BlackJack::BlackJack(std::size_t deckpile_s) :deckpile(deckpile_s) {}

void BlackJack::addPlayer(std::size_t bank) {
	players.push_back(BJ_Player(bank));
}

void BlackJack::players_makeBet() {
    int count = 1;
    for (auto& i : players) {
        std::cout << "You are player number: " << count<<". Your money:" << i.getMoney()<<std::endl;
        std::cout << "Make a bet:";
        std::size_t bet = 0;
        std::cin >> bet;
        i.makeBet(bet);
        count++;
    }
}

void BlackJack::showCards() {
    std::cout << "----------SHOW CARDS AFTER FIRST HAND----------" << std::endl;
    dealer.view_FirstCard();
    int count = 1;
    for (auto& i : players) {
        std::cout << "Player number " << count << " has:"<< std::endl;
        i.viewInfo();
        count++;
    }
}

void BlackJack::startRound() {
    std::cout<<"----------ROUND STARTED----------"<<std::endl;

    players_makeBet();

    dealer.Hand_Out_Cards(players, deckpile);
    dealer.Hand_Out_Cards(players, deckpile);

    std::cout << std::endl << std::endl;

    showCards();

    int count = 1;

    std::cout << std::endl << std::endl;

    if(dealer.isBlackJack()) {
        //dealer.Distribute_Winnings(players); ???
        std::cout<<"DEALER WON - BlackJack"<<std::endl;
        /*for (auto& i : players) {
            dealer.Win(i.getBet());
        }*/
    }
    else {
        for (auto &i : players) {
            std::cout << "----------YOU ARE PLAYER----------" << std::endl;
            std::cout << "You are player number:" << count << std::endl;
            std::cout << "Your cards: " << std::endl;
            i.viewInfo();
            if (i.isBlackJack()) {
                std::cout << "Congratulations - BlackJack!" << std::endl;
            }
            else {
                char flag;
                std::cout<<"Action:";
                std::cin >> flag;
                if(flag == 'D') {
                    try {
                        i.Double();
                        dealer.giveOneMore_Card(i, deckpile);
                    }
                    catch(const char* str) {
                        std::cout<<str<<std::endl;
                    }
                    std::cout << "Your cards:" << std::endl;
                    i.viewInfo();
                    if(i.Points()>21) {
                        std::cout<<"YOU LOSE"<<std::endl;
                        flag = 'S';
                    }
                    else
                        flag = 'S';
                }
                if (flag == 'H') {
                    while (flag == 'H') {
                        dealer.giveOneMore_Card(i, deckpile);
                        std::cout << "Your cards:" << std::endl;
                        i.viewInfo();
                        if(i.Points()>21) {
                            std::cout<<"YOU LOSE"<<std::endl;
                            flag = 'S';
                        }
                        else if (i.Points()<= 20) {
                            std::cout<<"Action:";
                            std::cin >> flag;
                        }
                        else {
                            std::cout << "Congratulations - BlackJack!" << std::endl;
                            flag = 'S';
                        }
                    }
                }
            }
            count++;
        }


        std::cout << std::endl << std::endl;
        std::cout << "----------DEALER----------" << std::endl;
        //std::cout << "Dealer`s money: " << dealer.getMoney() << std::endl;
        std::cout << "Dealer`s cards: " << std::endl;
        dealer.Play(deckpile);
        dealer.viewInfo();
        if(dealer.isBlackJack()) {
            std::cout<<"BlackJack"<<std::endl;
        }
        dealer.Distribute_Winnings(players);
    }


    std::cout << std::endl << std::endl;
    std::cout << "----------COMPARING CARDS----------" << std::endl;
    count = 1;
    for (auto& i : players) {
        std::cout << "Player number " << count << " has money - " << i.getMoney() << std::endl;
        count++;
    }
    //std::cout << "Dealer has money - " << dealer.getMoney();
    std::cout << std::endl<<std::endl;
}

void BlackJack::startGame() {

	std::size_t num_players = 0;
	std::cout << "Enter number of players:";
	std::cin >> num_players;
	for (std::size_t i = 1; i <= num_players; i++) {
		std::size_t money = 0;
		std::cout << "Enter amount of money the player number " << i << " has:";
		std::cin >> money;
		players.emplace_back(money);
	}
    std::cout<<std::endl;

	std::cout<<"H - HIT. S - STAND. D - DOUBLE. C - CONTINUE ROUND"<<std::endl<<std::endl;

    char round_flag = 'C';


    while(round_flag=='C') {

        startRound();

        round_flag = 'N';
        int count = 1;
        for(auto it = players.begin(); it != players.end();) {
            if (it->getMoney() != 0) {
                char action;
                std::cout << "You are player number:" << count << ". C - CONTINUE ROUND" << std::endl;
                std::cout << "Action:";
                std::cin >> action;
                if (action != 'C') {
                    it = players.erase(it);
                }
                else {
                    round_flag = action;
                    it->clearHand();
                    ++it;
                }
            }
            else {
                it = players.erase(it);
            }
            count++;
        }
        dealer.clearHand();
    }
}
