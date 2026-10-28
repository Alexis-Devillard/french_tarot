#include "controler.h"

Controler::Controler()
{
}

/**
 * @brief Constructs a controller for a game with the specified number of players.
 *
 * Creates the players and initializes the deck.
 * @throws std::invalid_argument if the number of players is not between 3 and 5.
 */
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

    // Deck init
    deck = Deck();
}

void Controler::startNewGame()
{
    // Initial distribution setup
    dealer = &players[0];
    cutter = &players[1];

    // Player setup
    for (Player& player: this->players) {
        player.setScore(0);
    }

    // Drawpile setup
    this->deck.initDrawPile();
}

/**
 * @brief Returns a text representation of the controller.
 */
string Controler::display() const
{
    string result;
    result += "====== Players ======\n";
    for (const Player& player : players)
    {
        result += player.getName() + "\t";
        result += "Score: " + std::to_string(player.getScore()) + "\n";
    }

    result += "====== Deck ======\n";
    result += "Nombre cartes deck: " + std::to_string(deck.getDrawPileSize()) + "\n";
    
    return result;
}

std::ostream &operator<<(std::ostream &os, const Controler &controler)
{
    return os << controler.display();
}
