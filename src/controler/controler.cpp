#include "controler.h"

#include <random>
#include <stdexcept>

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
}

/**
 * @brief Resets player scores and prepares all clases for a new game.
 *
 * Sets the first two players as dealer and cutter, then initializes the draw pile.
 * Card distribution is then lunched.
 */
void Controler::startNewGame()
{
    if (players.empty())
    {
        throw std::logic_error("Cannot start a game without players.");
    }

    // Initial distribution setup
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> dist(0, players.size() - 1);
    this->dealerIndex = dist(gen);

    // Player setup
    for (Player& player: this->players) {
        player.reset();
    }

    // Drawpile setup
    this->deck.initDrawPile();
}

void Controler::distributeCards()
{
    const std::size_t playerCount = players.size();
    if (playerCount == 0)
    {
        throw std::logic_error("Cannot distribute cards without players.");
    }

    const std::size_t drawPileSize = deck.getDrawPileSize();
    const std::size_t dogSize = (playerCount == 5) ? 3 : 6;

    if (drawPileSize < dogSize)
    {
        throw std::logic_error("Not enough cards in the draw pile.");
    }

    const std::size_t cardsPerPlayer = (drawPileSize - dogSize) / playerCount;

    if ((drawPileSize - dogSize) % playerCount != 0 || cardsPerPlayer % 3 != 0)
    {
        throw std::logic_error("The draw pile cannot be distributed evenly.");
    }

    const std::size_t firstPlayer = (this->dealerIndex + 1) % playerCount;

    for (std::size_t packet = 0; packet < cardsPerPlayer / 3; ++packet)
    {
        for (std::size_t offset = 0; offset < playerCount; ++offset)
        {
            // Draw 3 cards from the deck and add them to this player’s hand.
            for (size_t i = 0; i < 3; i++)
            {
                this->players[(firstPlayer + offset) % playerCount].addCardToHand(this->deck.drawCard());
            }   
        }

        // Add cards to the dog if not already full
        if (packet * 3 < dogSize)
        {
            for (size_t i = 0; i < 3; i++)
            {
                this->board.addCardToDog(this->deck.drawCard());
            }
        }
        
    }
}

std::size_t Controler::getDealerIndex() const
{
    return std::size_t();
}

/**
 * @brief Returns a text representation of the controller.
 */
string Controler::display() const
{
    // TODO: replace by the classes own display function
    string result;
    result += "====== Players ======\n";
    for (const Player& player : this->players)
    {
        result += player.getName() + "\t";
        result += "Score: " + std::to_string(player.getScore()) + "\t";
        result += "Nombre cartes main: " + std::to_string(player.getHandSize()) + "\n";
    }

    result += "====== Board ======\n";
    result += "Nombre cartes chien: " + std::to_string(this->board.getDogSize()) + "\n";

    result += "====== Deck ======\n";
    result += "Nombre cartes deck: " + std::to_string(this->deck.getDrawPileSize()) + "\n";
    
    return result;
}

std::ostream &operator<<(std::ostream &os, const Controler &controler)
{
    return os << controler.display();
}
