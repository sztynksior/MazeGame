#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates, const std::pair<int, int>& pFinishCoordinateS)
{

	maxMazeX = pMaxMazeX;
	maxMazeY = pMaxMazeY;

	startingCoordinates = pStartingCoordinates;
	finishCoordinates = pFinishCoordinateS;
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