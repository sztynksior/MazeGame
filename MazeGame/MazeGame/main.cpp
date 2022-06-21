#include "SquareMazeGenerator.h"
#include "Game.h"
#include "Player.h"
#include "TextureMenager.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

int main()
{
    TextureMenager T1("Textures");
    T1.SetTextureMap();

    Game& Game1 = Game::getInstance(900, 900);

    Game1.setPlayer(new Player(T1.getTextureWithGivenName("Player"), { 1 * 16, 1 * 16 }));
    Game1.setMaze(new SquareMaze(T1.getTextureWithGivenName("SquareFloor"), T1.getTextureWithGivenName("SquareWall"), T1.getTextureWithGivenName("SquareDoor"), { 0, 0 }, 5, 5));
    Game1.setMenu(new Menu(900, 900), T1);

    Game1.runGame();
}