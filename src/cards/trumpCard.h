#pragma once

#include <string>
#include "card.h"

using std::string;

class TrumpCard : public Card
{
private:
    
public:
    TrumpCard(string value);

    // ==== Getter/Setter ====
    Kind kind() const override;

    // ==== UI ====
    string display() const override;
};