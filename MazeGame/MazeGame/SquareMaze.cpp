#include "SquareMaze.h"

SquareMaze::SquareMaze(MazeElement* pFloor, MazeElement* pWall, MazeElement* pDoor, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY)
	: Maze(pFloor, pWall, pDoor, pInitialPosition, pMaxMazeX, pMaxMazeY)
{
	this->mazePlan = new SquareMazeGenerator(pMaxMazeX, pMaxMazeY, { (pMaxMazeX / 2) - 1, 0 }, { (pMaxMazeX / 2) - 1, pMaxMazeY - 1 });

	this->createMaze();
}
