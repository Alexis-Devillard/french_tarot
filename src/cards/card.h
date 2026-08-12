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
    virtual ~Card() = default;

    // ==== Getters/Setters ====
    string getValue() const;

    // ==== UI ====
    virtual string display() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Card& card);