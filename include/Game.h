#ifndef GAME_H
#define GAME_H

#include "Letter.h"

#include <vector>


class Game
{
    sf::RenderWindow* window;
    sf::Event event;

    std::vector<Letter*> letters;

    void initWindow();

public:
    Game();
    virtual ~Game();


    void run();


    void updatePollEvent();
    void SpawnLetters();
    void updateLetters();
    void update();


    void render();
};

#endif // GAME_H
