#include "player.h"

Player::Player(string name)
{
    this->name = name;
}

string Player::getName() const
{
    return name;
}

void Player::setName(string &name)
{
    this->name = name;
}
