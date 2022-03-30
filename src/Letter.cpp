#include "Letter.h"

void Letter::initLetter()
{
    this->l = 'a' + rand()%26;
}

Letter::Letter()
{
    this->initLetter();
}

Letter::~Letter()
{
    //dtor
}

char Letter::getLetter()
{
    return this->l;
}
