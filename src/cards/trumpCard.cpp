#include "trumpCard.h"

TrumpCard::TrumpCard(string value) : Card(value)
{
}

string TrumpCard::display() const
{
    return "Trump " + this->getValue();
}
