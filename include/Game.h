#ifndef GAME_H
#define GAME_H

#include "Letter.h"
#include "Player.h"

#include <vector>
#include <sstream>


class Game
{
    sf::RenderWindow* window;
    sf::Event event;
    sf::Clock FPS;
    sf::Text text, GameOverText;
    sf::Font font;

    std::vector<Letter*> letters;
    int currentNumber, MaxNumber;
    int points;

    bool pause;

    Player player;

    void initWindow();
    void initText();
    void initLetters();

public:
    Game();
    virtual ~Game();


    void run();


    bool isRunning();
    void updatePollEvent();
    void SpawnLetters();
    void updateLetters();
    void updateFPS();
    void update();


    void render();
};

#endif // GAME_H
