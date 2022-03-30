#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Crazy Letters", sf::Style::Close | sf::Style::Titlebar);


}

Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

void Game::run()
{
    while(this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Game::update()
{
    while(this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

        }
}

void Game::render()
{
    this->window->clear();



    this->window->display();
}
