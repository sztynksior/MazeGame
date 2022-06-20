#include "SquareMazeGenerator.h"
#include "Game.h"
#include "Player.h"
#include "TextureMenager.h"
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

    Game1.setPlayer(new Player(T1.getTextureWithGivenName("Player"), { 1 * 16, 0 }));

    Game1.runGame();
}