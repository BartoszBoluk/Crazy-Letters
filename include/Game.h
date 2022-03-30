#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>


class Game
{
    sf::RenderWindow* window;
    sf::Event event;

    void initWindow();

public:
    Game();
    virtual ~Game();


    void run();
    void update();
    void render();
};

#endif // GAME_H
