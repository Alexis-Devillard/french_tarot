#include "controler/controler.h"

#include <iostream>


int main() {
    
    Controler controler = Controler(5);

    controler.initNewGame();
    controler.distributeCards();

    controler.getPlayer(0).setBid(Bids::Guard_against_dog);

    std::cout << controler << std::endl;

    return 0;
}