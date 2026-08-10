#include "cards/card.h"
#include <iostream>


int main() {
    Card roi = Card("Roi");
    Card nb = Card("8");

    std::cout << roi << std::endl;
    std::cout << nb << std::endl;

    return 0;
}