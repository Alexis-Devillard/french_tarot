#include "card.h"

Card::Card(string value)
{
    Card::value = value;
}

string Card::getValue() const
{
    return Card::value;
}

string Card::display() const
{
    return "Card : " + Card::getValue();
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    return os << card.display();
}
