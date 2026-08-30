#include "deck.h"
#include "../cards/colorCard.h"
#include "../cards/trumpCard.h"

#include <string>
#include <random>
#include <iostream>
#include <stdexcept>
using std::string;

/** 
 * @brief Constructs a standard French Tarot deck. 
 * 
 * Creates the 78 cards composing a French Tarot deck:
 * - 56 suited cards: 4 suits with cards from 1 to 10, followed by Jack, Knight, Queen and King.
 * - 22 trump cards, numbered from 0 to 21.
 * 
 * The cards are stored in the deck's owning container.
 * The draw pile is initialized separately using initDrawPile(). 
*/
Deck::Deck()
{
    // Color cards
    const std::vector<std::string> suits = {
        "Heart",
        "Diamond",
        "Club",
        "Spade"
    };

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

    // Trumps cards
    for (size_t i = 0; i < 22; i++)
    {
        cards.emplace_back(
            std::make_unique<TrumpCard>(std::to_string(i))
        );
    }
}

/**
 * @brief Initializes the draw pile with all cards in the deck.
 * 
 * Clears the current draw pile and fill it with non-owning pointer to each card stored in the deck.
 */
void Deck::initDrawPile()
{
    drawPile.clear();

    for (const auto& card : cards)
    {
        drawPile.push_back(card.get());
    }
}

/**
 * @brief Draws a random card from the draw pile.
 * 
 * Selects a card at random, removes it from the draw pile
 * and returns a pointer to the selected card.
 */
Card* Deck::drawCard()
{
    if (drawPile.empty())
    {
        throw std::runtime_error("Can't draw from empty pile");
    }

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, drawPile.size() - 1);

    size_t index = dist(gen);
    Card* card = drawPile[index];

    drawPile.erase(drawPile.begin() + index);

    return card;
}

size_t Deck::getDrawPileSize() const
{
    return this->drawPile.size();
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
