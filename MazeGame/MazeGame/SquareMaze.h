#ifndef SQUARE_H
#define SQUARE_H

#include "MazeElement.h"
#include "Maze.h"
#include<SFML/Graphics.hpp>

class SquareMaze : public Maze
{
private:

	void createMaze();
	void defaultMazeInicialization();
	void makingPaths();
	void setingPositionsOfSprites();

public:

	SquareMaze(MazeElement* pFloor, MazeElement* pWall, MazeElement* pDoor, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY);
};

#endif // !SQUARE_H
