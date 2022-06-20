#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates)
{

	this->maxMazeX = pMaxMazeX;
	this->maxMazeY = pMaxMazeY;

	this->startingCoordinates = pStartingCoordinates;
}

MazeGenerator::~MazeGenerator()
{

	for (int i = 0; i < this->maxMazeX; i++)
	{
		for (int j = 0; j < this->maxMazeY; j++)
		{
			delete this->maze[i][j];
		}
	}
}