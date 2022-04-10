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

    sf::FloatRect getBounds() const;
    char getLetter();
    const int getPosY() const;

    void updatePos(int x, int y);

    void update();
    void render(sf::RenderTarget& target);

};

#endif // LETTER_H
