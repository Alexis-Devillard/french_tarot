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

void Board::setDogVisibility(bool visibility)
{
    this->canPlayerSeeDog = visibility;
}

void Board::setisDogAlreadyTaken(bool isDogAlreadyTaken)
{
    this->isDogAlreadyTaken = isDogAlreadyTaken;
}

void Board::setisDogForTaker(bool isForTaker)
{
    this->isDogForTaker = isDogForTaker;
}

void Board::emptyDog()
{
    this->dog.clear();
}

Card* Board::popDogCard()
{
    if (this->getDogSize() == 0)
    {
        throw std::logic_error("Can't pop an empty dog");
    }
    
    Card* card = dog.back();
    dog.pop_back();
    return card;
}

Card* Board::getDogCard(size_t index)
{
    if (index >= this->getDogSize())
    {
        throw std::invalid_argument("Index can't be bigger than dog size.");
    }
    
    return this->dog[index];
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
