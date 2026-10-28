#pragma once

#include <vector>

#include "../cards/card.h"

class Board
{
private:
    std::vector<Card*> dog;
public:
    Board();

    // === Game Logic ===
    void addCardToDog(Card* card);

    // === Getter/setter ===
    std::size_t getDogSize() const;
};
