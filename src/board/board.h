#pragma once

#include <vector>
#include <string>

#include "../cards/card.h"

using std::string;

class Board
{
private:
    std::vector<Card*> dog;

    bool canPlayerSeeDog;
    bool isDogAlreadyTaken;
    bool isDogForTaker;
public:
    Board();

    // === Game Logic ===
    void addCardToDog(Card* card);

    // === Getter/setter ===
    std::size_t getDogSize() const;
    void setDogVisibility(bool visibility);
    void setisDogAlreadyTaken(bool isDogAlreadyTaken);
    void setisDogForTaker(bool isForTaker);

    void emptyDog();

    Card* popDogCard();
    Card* getDogCard(size_t index);

    // ==== UI ====
    string display() const;
};

std::ostream& operator<<(std::ostream& os, const Board& board);
