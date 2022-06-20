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

	virtual void createMaze() = 0;

public:

	Maze(MazeElement* pFloor, MazeElement* pWall, MazeElement* pDoor, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY);
	~Maze();
};

#endif // !MAZE_H
