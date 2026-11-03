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
    std::size_t dealerIndex;

    Deck deck;
    Board board;

public:
    Controler();
    Controler(int nbPlayers);

    // ==== Game operations ===
    void initNewGame();
    void distributeCards();

    // ==== Getters/Setters ====
    std::size_t getDealerIndex() const;

    // TODO: function that verify the offer of each player, choose the one with the biggest and make him the dude alone

    // ==== UI ====
    string display() const;
};

std::ostream& operator<<(std::ostream& os, const Controler& controler);
