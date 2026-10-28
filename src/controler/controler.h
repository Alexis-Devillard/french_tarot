#pragma once

#include <vector>
#include <memory>
#include <string>

#include "../player/player.h"
#include "../deck/deck.h"

using std::string;

class Controler
{
private:
    // TODO: distribution
    std::vector<Player> players;
    Player* dealer;
    Player* cutter;

    Deck deck;

public:
    Controler();
    Controler(int nbPlayers);

    // ==== Game operations ===
    void startNewGame();

    // ==== Getters/Setters ====

    // ==== UI ====
    string display() const;
};

std::ostream& operator<<(std::ostream& os, const Controler& controler);
