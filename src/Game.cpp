#include "Game.h"

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(1280,720), "Crazy Letters", sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(60);
    window->setVerticalSyncEnabled(false);

    pause = false;
}

void Game::initText()
{
    if(!this->font.loadFromFile("Fonts/arial.ttf"))
    {
        std::cout <<"ERROR: INIT FONT";
    }

    this->text.setFont(this->font);
    this->text.setCharacterSize(20);
    this->text.setPosition(sf::Vector2f(10,10));
    this->text.setString("FPS: ");

    this->GameOverText.setFont(this->font);
    this->GameOverText.setCharacterSize(50);
    this->GameOverText.setPosition(sf::Vector2f(300,300));
    this->GameOverText.setString("Game Over \nPress ESCAPE to close the game");
}

void Game::initLetters()
{
    this->currentNumber = 0;
    this->MaxNumber = 3;
    this->points = 0;

    letters.push_back(new Letter());
}

Game::Game()
{
    this->initWindow();
    this->initText();
    this->initLetters();
}

Game::~Game()
{
    delete this->window;
}

void Game::run()
{
    while(this->window->isOpen())
    {
        this->updatePollEvent();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && pause == false)
            {
                pause = true;
            }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && pause == true)
            {
                pause = false;
            }

        if(pause == false && isRunning() == true)
        {
            this->update();
            this->render();
        }
    }
}

bool Game::isRunning()
{
    if(this->player.getHP()>0)
        return true;
    else
        return false;
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

void Game::SpawnLetters()
{
    if(this->currentNumber<this->MaxNumber)
    {
        currentNumber++;
        letters.push_back(new Letter());
    }
}

void Game::updateLetters()
{
    for(int i=0; i<letters.size(); i++)
    {
        if(sf::Keyboard::isKeyPressed&&event.Event::key.code==letters[i]->getLetter())
        {
            currentNumber--;
            this->letters.erase(letters.begin()+i);
            points++;
        }

        if(letters[i]->getPosY()>this->window->getSize().y)
        {
            currentNumber--;
            this->letters.erase(letters.begin()+i);
            this->player.loseHP(10);

            if(points>0)
                points--;
        }
    }

}

void Game::updateFPS()
{
    float currentTime = FPS.restart().asSeconds();
    int fps = 1 / (currentTime);

    std::stringstream ss;

    ss << "FPS: " <<fps<<std::endl<<"Points: "<<points<<std::endl<<"HP: "<<player.getHP();

    this->text.setString(ss.str());
}

void Game::update()
{
    this->SpawnLetters();

    this->updateFPS();

    for(int i=0; i<this->letters.size(); i++)
    {
        letters[i]->update();
        //std::cout<<letters[i]->getLetter()<<std::endl;
    }

    this->updateLetters();
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

    this->window->draw(this->text);

    if(isRunning() == false)
        this->window->draw(this->GameOverText);


    this->window->display();


}
