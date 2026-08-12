#include "deck/deck.h"

#include <iostream>


int main() {
    Deck deck = Deck();

    //std::cout << deck << std::endl;

    deck.initDrawPile();
    for (size_t i = 0; i < deck.getSize(); i++)
    {
        std::cout << *deck.drawCard() << std::endl;
    }
    

    return 0;
}