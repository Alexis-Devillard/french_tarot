#include "cards/colorCard.h"
#include "cards/trumpCard.h"
#include <iostream>


int main() {
    ColorCard roi = ColorCard("Roi", "Coeur");
    TrumpCard trump = TrumpCard("8");

    Card& card1 = roi;
    Card& card2 = trump;

    std::cout << card1 << std::endl;
    std::cout << card2 << std::endl;

    return 0;
}