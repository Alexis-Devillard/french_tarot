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

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    return os << board.display();
}
