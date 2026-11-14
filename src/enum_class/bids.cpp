#include <iostream>
#include <string_view>

#include "./bids.h"

std::string to_string(Bids bid) {
    switch (bid) {
        case Bids::None:              return "None";
        case Bids::Small:             return "Small";
        case Bids::Guard:             return "Guard";
        case Bids::Guard_without_dog: return "Guard without dog";
        case Bids::Guard_against_dog: return "Guard against dog";
    }
    return "Unknown";
}

std::ostream& operator<<(std::ostream& os, Bids bid) {
    return os << to_string(bid);
}