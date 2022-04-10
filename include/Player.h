#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
    int HP;

public:
    Player();
    virtual ~Player();

    const int getHP() const;

    void loseHP(int x);
    void update();

};

#endif // PLAYER_H
