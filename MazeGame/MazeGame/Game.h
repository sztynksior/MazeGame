#ifndef GAME_H
#define GAME_H

#include "TextureMenager.h"
#include "Maze.h"
#include "SquareMaze.h"
#include "Player.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

class Game
{
private:

	int windowWidth;
	int windowLength;
	Player* player;
	Maze* maze;
	Menu* menu;
	int difficultyLevel;

	Game(int pWidth, int pLength);

	void collision();

public:

	static Game & getInstance(int pWidth, int pLength);
	~Game();

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	
	void runGame();
	void setPlayer(Player* pPlayer);
	void setMaze(Maze* pMaze);
	void setMenu(Menu* pMenu, TextureMenager& pTextureMenager);
	void nextLevel(int pDeltaMazeSize);
};

#endif // !GAME_H