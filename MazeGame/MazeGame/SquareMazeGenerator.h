#ifndef SQUAREMAZEGENERATOR_H
#define SQUAREMAZEGENERATOR_H

#include "MazeGenerator.h"
#include "SquareMazeCell.h"

class SquareMazeGenerator : public MazeGenerator
{
private:

	int maxMazeX, maxMazeY;
	std::pair<int, int> startingCoordinates;
	std::pair<int, int> finishCoordinates;
	std::vector<std::vector<MazeCell*>> maze;

	virtual void mazeInicialization();

public:

	SquareMazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates, const std::pair<int, int>& pFinishCoordinateS);
	~SquareMazeGenerator();

	virtual int getMaxMazeX() = 0;
	virtual int getMaxMazeY() = 0;
	virtual MazeCell* getAccessToCellWithGivenCoordinates(std::pair<int, int> pCoordinates) = 0;
	virtual MazeCell* getAccessToCellIndicatedByVector(const std::pair<int, int> pCellCoordinates, const std::pair<int, int> pVector) = 0;

};

#endif // !SQUAREMAZEGENERATOR_H