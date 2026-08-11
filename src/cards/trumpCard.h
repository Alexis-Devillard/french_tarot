#pragma once

#include <string>
#include "card.h"

using std::string;

class TrumpCard : public Card
{
private:
    
public:
    TrumpCard(string value);

    // ==== UI ====
    string display() const override;
};