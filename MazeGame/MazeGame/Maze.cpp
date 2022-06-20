#include "Maze.h"

Maze::Maze(MazeElement* pFloor, MazeElement* pWall, MazeElement* pDoor, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY)
{
	this->floor = pFloor->copy();
	this->wall = pWall->copy();
	this->door = pDoor->copy();
	this->initialPosition = pInitialPosition;
	this->maxMazeX = pMaxMazeX;
	this->maxMazeY = pMaxMazeY;
	
	if (this->door->getSpriteSize() == this->floor->getSpriteSize() and this->floor->getSpriteSize() == this->wall->getSpriteSize())
	{
		this->spritesSize = this->door->getSpriteSize();
	}
}

Maze::~Maze()
{
	delete this->floor;
	delete this->wall;
	delete this->door;

	for (std::vector<MazeElement*> iColumn : this->mazeLayout)
	{
		for (MazeElement* iMazeElement : iColumn)
		{
			delete iMazeElement;
		}
	}
}
