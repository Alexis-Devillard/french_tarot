#pragma once

#include <string>
#include <vector>

#include "../cards/card.h"
#include "../enum_class/bids.h"

using std::string;

class Player
{
private:
    string name;
    int score;
    std::vector<Card*> hand;
    Bids bid;

public:
    Player(string name);

    // === Game logic ===
    void reset();
    void addCardToHand(Card* card);
    void emptyHand();

    // ==== Getters/Setters ====
    string getName() const;
    void setName(string& name);

    int getScore() const;
    void setScore(int score);

    std::size_t getHandSize() const;
    std::size_t getNumberOfTrumps() const;

    Bids getBid() const;
    void setBid(Bids bid);
    
    bool hasOneOfTrump() const;

    // ==== UI ====
    string display() const;
};

std::ostream& operator<<(std::ostream& os, const Player& player);