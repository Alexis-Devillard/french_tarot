#pragma once

#include <string>
#include "card.h"

using std::string;

class ColorCard : public Card
{
private:
    string symbol;
public:
    ColorCard(string value, string symbol);

    // ==== Getters/Setters ====
    string getSymbol() const;
    Kind kind() const override;

    // ==== UI ====
    string display() const override;
};