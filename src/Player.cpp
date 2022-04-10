#include "Player.h"

Player::Player()
{
    this->HP = 100;
}

Player::~Player()
{
//    dtor
}

const int Player::getHP() const
{
    return this->HP;
}

void Player::loseHP(int x)
{
    this->HP-=x;
}


void Player::update()
{

}
