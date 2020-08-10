cmake_minimum_required(VERSION 3.16)
project(BlackJack)

set(CMAKE_CXX_STANDARD 17)

set(GAME_DIR "modules/Game")
set(CARDS_DIR "modules/Cards")
set(PLAYERS_DIR "modules/Players")

include_directories(${CARDS_DIR} ${GAME_DIR}  ${PLAYERS_DIR})

set(SOURCE
        main.cpp
        ${CARDS_DIR}/Card.cpp
        ${CARDS_DIR}/Deck.cpp
        ${CARDS_DIR}/DeckPile.cpp
        ${GAME_DIR}/BlackJack.cpp
        ${PLAYERS_DIR}/BJ_Player.cpp
        ${PLAYERS_DIR}/Dealer.cpp
        ${PLAYERS_DIR}/Dealer_Hand.cpp
        ${PLAYERS_DIR}/Dealer.cpp
        ${PLAYERS_DIR}/Hand.cpp
        ${PLAYERS_DIR}/Player.cpp
        )

add_executable(BlackJack ${SOURCE})

#target_link_libraries(${PROJECT_NAME} PRIVATE cxx_std_17)