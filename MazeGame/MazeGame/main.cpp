#include "SquareMazeGenerator.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>



class dupa
{
public:
    std::string cyce;
    int ile;

    dupa(int pIle, std::string gowna)
    {
        this->ile = pIle;
        this->cyce = gowna;
    }
};

class chuj
{
public:

    dupa* dupa1;

    chuj(dupa* pDupa)
    {
        this->dupa1 = pDupa;
    }
};

int main()
{
    chuj chuj1(new dupa(4, "jajaja"));

    std::cout << chuj1.dupa1->ile << " " << chuj1.dupa1->cyce;

    Game& Game1 = Game::getInstance(900, 900);

    Game1.runGame();
}