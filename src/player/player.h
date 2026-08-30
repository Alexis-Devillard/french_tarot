#pragma once

#include <string>

using std::string;

class Player
{
private:
    string name;
public:
    Player(string name);

    // ==== Getters/Setters ====
    string getName() const;
    void setName(string& name);
};
