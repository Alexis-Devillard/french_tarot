#include "card.h"

/**
 * @brief Creates a card with the given value.
 */
Card::Card(string value)
{
    this->value = value;
}

string Card::getValue() const
{
    return this->value;
}

/**
 * @brief Writes the card's text representation to a stream.
 */
std::ostream& operator<<(std::ostream& os, const Card& card)
{
    return os << card.display();
}
