#include "trumpCard.h"

/**
 * @brief Creates a trump card with the given value.
 */
TrumpCard::TrumpCard(string value) : Card(value)
{
}

Card::Kind TrumpCard::kind() const
{
    return Kind::Trump;
}

/**
 * @brief Returns the card's value prefixed with its trump type.
 */
string TrumpCard::display() const
{
    return "Trump " + this->getValue();
}
