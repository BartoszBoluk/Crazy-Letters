#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Crazy Letters", sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(false);
}

Game::Game()
{
    this->initWindow();

    letters.push_back(new Letter());



}

Game::~Game()
{
    delete this->window;
}

void Game::SpawnLetters()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        letters.push_back(new Letter());
}

void Game::run()
{
    while(this->window->isOpen())
    {
        this->updatePollEvent();

        this->update();
        this->render();
    }
}

void Game::updatePollEvent()
{
    while(this->window->pollEvent(event))
    {
        if(event.Event::type==sf::Event::Closed)
            this->window->close();
        if(event.Event::KeyPressed&&event.Event::key.code==sf::Keyboard::Escape)
            this->window->close();
    }
}

void Game::updateLetters()
{

}

void Game::update()
{
    this->SpawnLetters();

    for(int i=0; i<this->letters.size(); i++)
    {
        letters[i]->update();
        std::cout<<letters[i]->getLetter()<<std::endl;
    }
}

void Game::render()
{
    this->window->clear();

    for(int i=0; i<this->letters.size(); i++)
    {
        letters[i]->render(*this->window);
    }

   //letters[0].render(*this->window);
   // letters[1].render(*this->window);


    this->window->display();


}
