#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <filesystem>

class Game
{
private:

	int windowWidth;
	int windowLength;

	Game(int pWidth, int pLength);

public:

	static Game & getInstance(int pWidth, int pLength);

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void runGame();
};

#endif // !GAME_H