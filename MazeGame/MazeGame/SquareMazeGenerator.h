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

	virtual void mazeInicialization(); //TO DO: zmieñ dzia³anie funkcji 

public:

	SquareMazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates, const std::pair<int, int>& pFinishCoordinateS);
	~SquareMazeGenerator();

	int getMaxMazeX();
	int getMaxMazeY();
	MazeCell* getAccessToCellWithGivenCoordinates(std::pair<int, int> pCoordinates);
	MazeCell* getAccessToCellIndicatedByVector(const std::pair<int, int> pCellCoordinates, const std::pair<int, int> pIndicativeVector);

};

#endif // !SQUAREMAZEGENERATOR_H