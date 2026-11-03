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

    /**
     * @brief Destroys the card through its base-class interface.
     */
    virtual ~Card() = default;

    // ==== Getters/Setters ====
    string getValue() const;

    // ==== UI ====
    /**
     * @brief Returns a text representation of the card.
     */
    virtual string display() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Card& card);