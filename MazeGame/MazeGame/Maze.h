#ifndef MAZE_H
#define MAZE_H

#include "MazeElement.h"
#include "Floor.h"
#include "Wall.h"
#include "Door.h"
#include "SquareMazeGenerator.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Maze : public sf::Drawable
{
protected:

	sf::Vector2f initialPosition;
	int maxMazeX, maxMazeY;
	MazeElement* floor;
	MazeElement* wall;
	MazeElement* door;
	std::vector<std::vector<MazeElement*>> mazeLayout;
	SquareMazeGenerator* mazePlan;
	sf::Vector2u spritesSize;

	virtual void createMaze() = 0;

public:

	Maze(sf::Texture& pFloorTexture, sf::Texture& pWallTexture, sf::Texture& pDoorTexture, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY);
	~Maze();

	virtual void draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const = 0;
};

#endif // !MAZE_H
