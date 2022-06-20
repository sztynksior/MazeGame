#include "SquareMazeGenerator.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

int main()
{
    Game& Game1 = Game::getInstance(900, 900);

    Game1.runGame();
}