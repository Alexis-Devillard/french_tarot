#pragma once

#include <vector>
#include <memory>
#include <string>

#include "../player/player.h"
#include "../deck/deck.h"
#include "../board/board.h"

using std::string;

class Controler
{
private:
    std::vector<Player> players;
    std::size_t dealerIndex = 0;
    std::size_t takerIndex = 0;

    Deck deck;
    Board board;

public:
    Controler();
    Controler(int nbPlayers);

    // ==== Game operations ===
    void initNewGame();
    void initNewRound();

    void distributeCards();
    bool compareBids();

    bool distributeDog(Bids bid);


    // ==== Getters/Setters ====
    std::size_t getDealerIndex() const;
    std::size_t getTakerIndex() const;

    Player& getTaker();
    Player& getDealer();

    Player& getPlayer(std::size_t index);
    const Player& getPlayer(std::size_t index) const;

    // ==== UI ====
    string display() const;
};

std::ostream& operator<<(std::ostream& os, const Controler& controler);
