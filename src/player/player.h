#pragma once

#include <string>
#include <vector>

#include "../cards/card.h"

using std::string;

class Player
{
private:
    string name;
    int score;
    std::vector<Card*> hand;

public:
    Player(string name);

    // === Game logic ===
    void reset();
    void addCardToHand(Card* card);

    // ==== Getters/Setters ====
    string getName() const;
    void setName(string& name);

    int getScore() const;
    void setScore(int score);

    std::size_t getHandSize() const;
};
