#include "colorCard.h"

ColorCard::ColorCard(string value, string symbol) : Card(value)
{
    this->symbol = symbol;
}

string ColorCard::getSymbol() const
{
    return this->symbol;
}

string ColorCard::display() const
{
    return "Card : " + this->getValue() + " " + this->getSymbol();
}