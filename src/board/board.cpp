#include "board.h"

/**
 * @brief Constructs an empty board.
 */
Board::Board()
{
}

/**
 * @brief Adds a card to the dog.
 */
void Board::addCardToDog(Card *card)
{
    this->dog.push_back(card);
}

std::size_t Board::getDogSize() const
{
    return this->dog.size();
}

/**
 * @brief Returns a text representation of the board and its dog.
 */
string Board::display() const
{
    string result = "Number of cards in Dog: " + std::to_string(this->dog.size()) + "\n";

    result += "Dog:";
    for (Card* dog_card: this->dog)
    {
        result += "\t" + dog_card->display();
    }
    
    return result;
}

/**
 * @brief Writes the board's text representation to a stream.
 */
std::ostream &operator<<(std::ostream &os, const Board &board)
{
    return os << board.display();
}
