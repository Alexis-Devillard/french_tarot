#pragma once

enum class Bids {
    None,
    Small, 
    Guard, 
    Guard_without_dog, 
    Guard_against_dog
};

std::string to_string(Bids bid);
std::ostream& operator<<(std::ostream& os, Bids bid);
