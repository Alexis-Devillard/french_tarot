#pragma once

#include <vector>
#include <string>

#include "../cards/card.h"

using std::string;

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

    // ==== UI ====
    string display() const;
};

std::ostream& operator<<(std::ostream& os, const Board& board);
