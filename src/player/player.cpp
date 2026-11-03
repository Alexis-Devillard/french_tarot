#include "player.h"

/**
 * @brief Creates a player with the given name and an initial score of zero.
 */
Player::Player(string name)
{
    this->name = name;
    this->score = 0;
}

/**
 * @brief Resets the player's score and clears their hand.
 */
void Player::reset()
{
    this->score = 0;
    this->hand.clear();
}

/**
 * @brief Adds a card to the player's hand.
 */
void Player::addCardToHand(Card *card)
{
    this->hand.push_back(card);
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

/**
 * @brief Returns a text representation of the player.
 */
string Player::display() const
{
    string result = this->getName() + "\t";
    result += "Score: " + std::to_string(this->getScore()) + "\t";
    result += "Nombre cartes main: " + std::to_string(this->getHandSize());
    return result;
}

/**
 * @brief Writes the player's text representation to a stream.
 */
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    return os << player.display();
}
