#include "Game.h"

Game::Game(int pWidth, int pLength)
{
    this->windowWidth = pWidth;
    this->windowLength = pLength;
}

void Game::collision()
{
    for (std::vector<MazeElement*> i : this->maze->getMazeLayout())
    {
        for (MazeElement* j : i)
        {
            if (this->player->getNextPosition() == j->getSpritePosition())
            {
                if (j->onCollision() == "notPassable")
                {
                    this->player->stopMovement();
                    return;
                }
                else if (j->onCollision() == "finish")
                {
                    this->player->stopMovement();
                    this->nextLevel(this->difficultyLevel);
                    return;
                }
                else if (j->onCollision() == "flor")
                {
                    return;
                }
            }
        }
    }
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

    bool inGame = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!inGame)
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:

                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                    {
                        this->menu->moveUp();
                        break;
                    }
                    case sf::Keyboard::Down:
                    {
                        this->menu->moveDown();
                        break;
                    }
                    case sf::Keyboard::Return:
                    {
                        switch (this->menu->getPreessedButton())
                        {
                        case 0:
                        {
                            this->difficultyLevel = 1;
                            inGame = true;

                            break;
                        }
                        case 1:
                        {
                            this->difficultyLevel = 3;
                            inGame = true;

                            break;
                        }
                        case 2:
                        {
                            this->difficultyLevel = 5;
                            inGame = true;

                            break;
                        }
                        case 3:
                        {
                            window.close();
                            break;
                        }
                        }
                    }
                    default:
                    {
                        break;
                    }
                    }

                default:
                    break;
                }
            }
            else if(inGame)
            {
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        this->maze = this->firstMaze->copy(0);
                        this->player->setPosition({ 1 * 16, 1 * 16 });
                        inGame = false;
                    }
                }
            }
        }

        if (inGame)
        {
        this->player->setingMoveDirectionOnKeyPressed();
        this->collision();
        this->player->movement();
        }
 
        window.clear();
        if (!inGame)
        {
            window.draw(*this->menu);
        }
        else if (inGame)
        {
        window.draw(*this->maze);
        window.draw(*this->player);
        }

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

    this->firstMaze = this->maze->copy(0);
}

void Game::setMenu(Menu* pMenu, TextureMenager& pTextureMenager)
{
    this->menu = pMenu;
    pMenu = NULL;

    this->menu->setTextures(pTextureMenager);
    this->menu->setSprites();
}

void Game::nextLevel(int pDeltaMazeSize)
{
    Maze* tMazePointer = this->maze->copy(pDeltaMazeSize);
    this->player->setPosition({ 1 * 16, 1 * 16 });
    delete this->maze;
    this->maze = tMazePointer;
}
