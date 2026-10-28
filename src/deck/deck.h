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
    std::vector<Card*> drawPile;

public:
    Deck();
    Deck(const Deck&) = delete;
    Deck& operator=(const Deck&) = delete;

    void initDrawPile();
    Card* drawCard();

    // ==== Getters/Setters ====
    size_t getDrawPileSize() const;

    // ==== UI ====
   string display() const;
};

std::ostream& operator<<(std::ostream& os, const Deck& deck);