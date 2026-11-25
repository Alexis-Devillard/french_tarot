#include "controler/controler.h"

#include <iostream>


int main() {
    
    Controler controler = Controler(5);

    controler.initNewGame();

    controler.distributeCards();
    // Player do theirs bids
    controler.compareBids();
    // repeat until a taker is elected

    controler.distributeDog(controler.getTaker().getBid());
    // TODO: Discards cards for the takker if needed

    // Begin round

    return 0;
}