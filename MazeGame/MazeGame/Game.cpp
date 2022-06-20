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

Game::~Game()
{
    delete this->player;
}

void Game::runGame()
{
    sf::RenderWindow window(sf::VideoMode(this->windowWidth, this->windowLength), "MazeGame");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        this->player->setingMoveDirectionOnKeyPressed();
        this->player->movement();

        window.clear();
        window.draw(*this->maze);
        window.draw(*this->player);
        window.display();
    }
}

void Game::setPlayer(Player* pPlayer)
{
    this->player = pPlayer;
    pPlayer = NULL;
}

void Game::setMaze(Maze* pMaze)
{
    this->maze = pMaze;
    pMaze = NULL;
}
