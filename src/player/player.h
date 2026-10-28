#pragma once

#include <string>

using std::string;

class Player
{
private:
    string name;
    int score;
public:
    Player(string name);

    // ==== Getters/Setters ====
    string getName() const;
    void setName(string& name);

    int getScore() const;
    void setScore(int score);
};
