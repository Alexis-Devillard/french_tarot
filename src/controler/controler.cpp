#include "controler.h"

#include <random>
#include <stdexcept>

/**
 * @brief Constructs a controller without any players.
 */
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
 * Sets the dealer, then initializes the draw pile.
 *
 * @throws std::logic_error if the number of players is not between 3 and 5.
 */
void Controler::initNewGame()
{
    if (players.size() < 3 || players.size() > 5)
    {
        throw std::logic_error("Number of players must be between 3 and 5.");
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

/**
 * @brief Deals cards to each player and places the remaining cards in the dog.
 *
 * Cards are dealt in packets of three, starting with the player after the dealer.
 * @throws std::logic_error if there are no players, too few cards for the dog,
 * or the remaining cards cannot be distributed evenly in packets of three.
 */
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

    // Deal the cards
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

    // Verify that no player is dealt only the 1 of trumps and no others (counting the excuse as a trump) 
    // If yes: the hand is cancelled and the cards are thrown in and the next dealer deals.
    for (Player& player: this->players) {
        if (player.getNumberOfTrumps() == 1)
        {
            if (player.hasOneOfTrump())
            {
                this->initNewRound();
                this->distributeCards();
            }
        }
    }
}

void Controler::initNewRound()
{
    for (Player& player: this->players) {
        player.emptyHand();
    }
    this->deck.initDrawPile();
    this->dealerIndex = (this->dealerIndex + 1) % this->players.size();
}

std::size_t Controler::getDealerIndex() const
{
    return this->dealerIndex;
}

/**
 * @brief Returns a text representation of the controller.
 */
string Controler::display() const
{
    string result;
    result += "====== Players ======\n";
    for (const Player& player : this->players)
    {
        result += player.display() + "\n";
    }

    result += "====== Board ======\n";
    result += this->board.display() + "\n";

    result += "====== Deck ======\n";
    result += this->deck.display() + "\n";
    
    return result;
}

/**
 * @brief Writes the controller's text representation to a stream.
 */
std::ostream &operator<<(std::ostream &os, const Controler &controler)
{
    return os << controler.display();
}
