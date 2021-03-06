#include "Maze.h"

Maze::Maze(sf::Texture& pFloorTexture, sf::Texture& pWallTexture, sf::Texture& pDoorTexture, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY)
{
	this->floor = new Floor(pFloorTexture);
	this->wall = new Wall(pWallTexture);
	this->door = new Door(pDoorTexture);
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

std::vector<std::vector<MazeElement*>>& Maze::getMazeLayout()
{
	return this->mazeLayout;
}