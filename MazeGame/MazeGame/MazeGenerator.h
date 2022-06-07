#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include "MazeCell.h"
#include <vector>
#include <utility>
#include <stack>

class MazeGenerator
{
protected:

	int maxMazeX, maxMazeY;
	std::pair<int, int> startingCoordinates;
	std::pair<int, int> finishCoordinates;
	std::vector<std::vector<MazeCell*>> maze;

private:

	virtual void mazeInicialization() = 0;
	virtual std::pair<int, int> lookingForNeighbours(std::pair<int, int> pCellCoordinates) = 0;

public:


	MazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates, const std::pair<int, int>& pFinishCoordinateS);
	~MazeGenerator();

	virtual int getMaxMazeX() = 0;
	virtual int getMaxMazeY() = 0;
	virtual MazeCell* getAccessToCellWithGivenCoordinates(std::pair<int, int> pCoordinates) = 0;
	virtual MazeCell* getAccessToCellIndicatedByVector(const std::pair<int, int> pCellCoordinates, const std::pair<int, int> pVector) = 0;
};

#endif // !MAZEGENERATOR_H