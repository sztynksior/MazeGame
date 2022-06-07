#ifndef SQUAREMAZEGENERATOR_H
#define SQUAREMAZEGENERATOR_H

#include "MazeGenerator.h"
#include "SquareMazeCell.h"
#include <cstdlib>
#include <ctime>

class SquareMazeGenerator : public MazeGenerator
{
private:

	virtual void mazeInicialization();
	void lookingForNeighbours(std::vector<std::pair<int, int>>& pNotVisitedNeighbours, std::pair<int, int> pCellCoordinates);

public:

	SquareMazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates, const std::pair<int, int>& pFinishCoordinateS);
	~SquareMazeGenerator();

	int getMaxMazeX();
	int getMaxMazeY();
	MazeCell* getAccessToCellWithGivenCoordinates(std::pair<int, int> pCoordinates);
	MazeCell* getAccessToCellIndicatedByVector(const std::pair<int, int> pCellCoordinates, const std::pair<int, int> pIndicativeVector);

};

#endif // !SQUAREMAZEGENERATOR_H