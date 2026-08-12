#include "deck.h"
#include "../cards/colorCard.h"

#include <string>
using std::string;

Deck::Deck()
{
    const std::vector<std::string> suits = {
        "Heart",
        "Diamond",
        "Club",
        "Spade"
    };

    // Color cards
    for (const std::string& suit : suits) {
        for (size_t i = 1; i < 11; i++) {
            cards.emplace_back(
                std::make_unique<ColorCard>(std::to_string(i), suit)
            );
        }

        cards.emplace_back(std::make_unique<ColorCard>("Jack", suit));
        cards.emplace_back(std::make_unique<ColorCard>("Knight", suit));
        cards.emplace_back(std::make_unique<ColorCard>("Queen", suit));
        cards.emplace_back(std::make_unique<ColorCard>("King", suit));
    }
}

string Deck::display() const
{
    string result = "";
    for (size_t i = 0; i < this->cards.size(); i++)
    {
        result += this->cards[i]->display();
        result += "\n";
    }

    return result;
}

std::ostream &operator<<(std::ostream &os, const Deck &deck)
{
    return os << deck.display();
}
