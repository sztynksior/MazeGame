#ifndef SQUARE_H
#define SQUARE_H

#include "MazeElement.h"
#include "Maze.h"
#include<SFML/Graphics.hpp>

class SquareMaze : public Maze
{
private:

	SquareMaze(const SquareMaze& pSquareMaze, int pDeltaSize);

	void createMaze();
	void defaultMazeInicialization();
	void makingPaths();
	void setingPositionsOfSprites();

public:

	SquareMaze(sf::Texture& pFloorTexture, sf::Texture& pWallTexture, sf::Texture& pDoorTexture, sf::Vector2f pInitialPosition, int pMaxMazeX, int pMaxMazeY);

	Maze* copy(int pDeltaSize);
	void draw(sf::RenderTarget& pTarget, sf::RenderStates pStates) const;
};

#endif // !SQUARE_H
