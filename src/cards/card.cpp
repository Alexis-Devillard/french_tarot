#include "card.h"

Card::Card(string value)
{
    this->value = value;
}

string Card::getValue() const
{
    return this->value;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    return os << card.display();
}
