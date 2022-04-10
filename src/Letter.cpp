#include "Letter.h"

void Letter::initLetter()
{
    this->l = 'a' + rand()%26;
    int x = rand()%1230;

    this->letter.setFillColor(sf::Color::Red);
    this->letter.setSize(sf::Vector2f(50,50));
    this->letter.setPosition(sf::Vector2f(x,20));
    this->letter.setOutlineThickness(3);

    if(!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cout <<"ERROR: INIT FONT";
    }

    this->text.setFont(this->font);
    this->text.setCharacterSize(50);
    this->text.setPosition(sf::Vector2f(x+5,13));
    this->text.setString(l);

}

Letter::Letter()
{
    this->initLetter();
}

Letter::~Letter()
{
    //dtor
}

sf::FloatRect Letter::getBounds() const
{
    return this->letter.getGlobalBounds();
}

char Letter::getLetter()
{
    return this->l;
}

const int Letter::getPosY() const
{
    return this->letter.getPosition().y;
}

void Letter::updatePos(int x, int y)
{
    this->letter.setPosition(sf::Vector2f(x,y));
    this->text.setPosition(sf::Vector2f(x,y));
}

void Letter::update()
{
    this->letter.move(0,3);
    this->text.move(0,3);
}

void Letter::render(sf::RenderTarget& target)
{
    target.draw(this->letter);
    target.draw(this->text);
}
