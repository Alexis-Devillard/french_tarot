#pragma once

#include <string>
#include <ostream>
#include <vector>
#include <memory>

#include "../cards/card.h"

using std::string;

class Deck
{
private:
    std::vector<std::unique_ptr<Card>> cards;

public:
    Deck();

    // ==== UI ====
   string display() const;
};

std::ostream& operator<<(std::ostream& os, const Deck& deck);