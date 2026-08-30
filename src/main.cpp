#include "controler/controler.h"

#include <iostream>


int main() {
    
    Controler controler = Controler(5);

    std::cout << controler << std::endl;

    return 0;
}