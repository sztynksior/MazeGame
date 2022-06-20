#ifndef GAME_H
#define GAME_H

#include "TextureMenager.h"
#include "Maze.h"
#include "SquareMaze.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <filesystem>

class Game
{
private:

	int windowWidth;
	int windowLength;
	Player* player;

	Game(int pWidth, int pLength);

public:

	static Game & getInstance(int pWidth, int pLength);
	~Game();

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void runGame();
	void setPlayer(Player* pPlayer);
};

#endif // !GAME_H