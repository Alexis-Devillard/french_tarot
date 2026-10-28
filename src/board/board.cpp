#include "board.h"

Board::Board()
{
}

void Board::addCardToDog(Card *card)
{
    this->dog.push_back(card);
}

std::size_t Board::getDogSize() const
{
    return this->dog.size();
}
