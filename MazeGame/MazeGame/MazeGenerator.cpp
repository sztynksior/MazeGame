#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates, const std::pair<int, int>& pFinishCoordinateS)
{

	this->maxMazeX = pMaxMazeX;
	this->maxMazeY = pMaxMazeY;

	this->startingCoordinates = pStartingCoordinates;
	this->finishCoordinates = pFinishCoordinateS;

	this->mazeInicialization();
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