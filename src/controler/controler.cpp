#include "controler.h"

Controler::Controler()
{
}

Controler::Controler(int nbPlayers)
{
    // Player init
    if (nbPlayers < 3 || nbPlayers > 5)
    {
        throw std::invalid_argument("Number of players must be between 3 and 5.");
    }

    players.reserve(nbPlayers);

    for (int i = 0; i < nbPlayers; ++i)
    {
        players.emplace_back(Player(std::to_string(i + 1)));
    }

    dealer = &players[0];
    cutter = &players[1];

    // Deck init
    deck = Deck();
}

string Controler::display() const
{
    string result;
    result += "====== Players ======\n";
    for (const Player& player : players)
    {
        result += player.getName() + "\n";
    }

    result += "====== Deck ======\n";
    result += "Nombre cartes deck: " + std::to_string(deck.getSize()) + "\n";
    
    return result;
}

std::ostream &operator<<(std::ostream &os, const Controler &controler)
{
    return os << controler.display();
}
