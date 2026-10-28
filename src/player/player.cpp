#include "player.h"

Player::Player(string name)
{
    this->name = name;
    this->score = 0;
}

void Player::reset()
{
    this->score = 0;
    this->hand.clear();
}

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
