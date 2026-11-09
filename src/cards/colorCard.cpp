#include "colorCard.h"

/**
 * @brief Creates a suited card with the given value and suit symbol.
 */
ColorCard::ColorCard(string value, string symbol) : Card(value)
{
    this->symbol = symbol;
}

string ColorCard::getSymbol() const
{
    return this->symbol;
}

Card::Kind ColorCard::kind() const
{
    return Kind::Color;
}

/**
 * @brief Returns the card's value followed by its suit symbol.
 */
string ColorCard::display() const
{
    return this->getValue() + " " + this->getSymbol();
}