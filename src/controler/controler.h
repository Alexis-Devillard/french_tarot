#pragma once

#include <vector>
#include <memory>
#include <string>

#include "../player/player.h"

using std::string

class Controler
{
private:
    // TODO: distribution
    std::vector<Player> players;

public:
    Controler(int nbPlayers);

    addPlayer(string name);
};
