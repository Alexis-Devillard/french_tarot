#include "player.h"

/**
 * @brief Creates a player with the given name and an initial score of zero.
 */
Player::Player(string name)
{
    this->name = name;
    this->score = 0;
    this->bid = Bids::None;
}

/**
 * @brief Resets the player's score, clears their hand and bid.
 */
void Player::reset()
{
    this->score = 0;
    this->hand.clear();
    this->bid = Bids::None;
}

/**
 * @brief Adds a card to the player's hand.
 */
void Player::addCardToHand(Card *card)
{
    this->hand.push_back(card);
}

void Player::addCardToWonCards(Card *card)
{
    this->wonCards.push_back(card);
}

void Player::emptyHand()
{
    this->hand.clear();
}

string Player::getName() const
{
    return name;
}

void Player::setName(string &name)
{
    this->name = name;
}

int Player::getScore() const
{
    return this->score;
}

void Player::setScore(int score)
{
    this->score = score;
}

std::size_t Player::getHandSize() const
{
    return this->hand.size();
}

std::size_t Player::getNumberOfTrumps() const
{
    std::size_t nb = 0;
    for (Card* card: this->hand)
    {
        if (card->isTrump())
        {
            nb += 1;
        }
    }
    return nb;
}

Bids Player::getBid() const
{
    return this->bid;
}

void Player::setBid(Bids bid)
{
    this->bid = bid;
}

bool Player::hasOneOfTrump() const
{
    for (Card* card: this->hand)
    {
        if (card->isTrump() && card->getValue() == "1")
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Returns a text representation of the player.
 */
string Player::display() const
{
    string result = this->getName() + "\t";
    result += "Score: " + std::to_string(this->getScore()) + "\t";
    result += "Nombre cartes main: " + std::to_string(this->getHandSize()) + "\t";
    result += "Bid: " + to_string(this->getBid());
    return result;
}

/**
 * @brief Writes the player's text representation to a stream.
 */
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    return os << player.display();
}
