#ifndef LETTER_H
#define LETTER_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Letter
{
    char l;
    sf::RectangleShape letter;
    sf::Text text;
    sf::Font font;

    void initLetter();

public:
    Letter();
    virtual ~Letter();

    char getLetter();

    void updatePos(int x, int y);

    void update();
    void render(sf::RenderTarget& target);

};

#endif // LETTER_H
