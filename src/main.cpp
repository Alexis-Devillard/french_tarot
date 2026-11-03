#include "controler/controler.h"

#include <iostream>


int main() {
    
    Controler controler = Controler(5);

    std::cout << controler << std::endl;

    controler.initNewGame();

    std::cout << controler << std::endl;

    controler.distributeCards();

    std::cout << controler << std::endl;

    return 0;
}