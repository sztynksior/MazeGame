#include "Game.h"

Game::Game(int pWidth, int pLength)
{
    this->windowWidth = pWidth;
    this->windowLength = pLength;
}

Game& Game::getInstance(int pWidth, int pLength)
{
    static Game instance(pWidth, pLength);
    return instance;
}

void Game::runGame()
{
    sf::RenderWindow window(sf::VideoMode(this->windowWidth, this->windowLength), "MazeGame");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
