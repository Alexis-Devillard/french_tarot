#include "player.h"

Player::Player(string name)
{
    this->name = name;
    this->score = 0;
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
