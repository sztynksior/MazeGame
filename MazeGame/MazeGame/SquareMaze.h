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

	SquareMaze(sf::Texture& pFloorTexture, sf::Texture& pWallTexture, sf::Texture& pDoorTexture, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY);
	SquareMaze(MazeElement* pFloor, MazeElement* pWall, MazeElement* pDoor, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY);

	void draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const;
};

#endif // !SQUARE_H
