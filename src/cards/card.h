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

    enum class Kind { Trump, Color };

    // Logic
    virtual Kind kind() const = 0;

    // ==== Getters/Setters ====
    string getValue() const;

    bool isTrump() const { return kind() == Kind::Trump; }
    bool isColor() const { return kind() == Kind::Color; }

    // ==== UI ====
    /**
     * @brief Returns a text representation of the card.
     */
    virtual string display() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Card& card);