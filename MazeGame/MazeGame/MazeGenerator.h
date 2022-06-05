#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include "MazeCell.h"
#include <vector>
#include <utility>
#include <stack>

class MazeGenerator
{
private:

	int maxMazeX, maxMazeY;
	std::pair<int, int> startingCoordinates;
	std::vector<std::vector<MazeCell*>> maze;

	MazeCell* getAccessToCellIndicatedByVector(const std::pair<int, int> pCellCoordinates, const std::pair<int, int> pVector);
	void mazeInicialization();

public:

	MazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates);
	~MazeGenerator();

	int getMaxMazeX();
	int getMaxMazeY();
	MazeCell* getAccessToCellWithGivenCoordinates(std::pair<int, int> pCoordinates);
};

#endif // !MAZEGENERATOR_H