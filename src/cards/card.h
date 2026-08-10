#pragma once

#include <string>
#include <ostream>

using std::string;

class Card
{
private:
    string value;
    
public:
    Card(string value);

    // ==== Getters/Setters ====
    string getValue() const;

    // ==== UI ====
    string display() const;
};

std::ostream& operator<<(std::ostream& os, const Card& card);