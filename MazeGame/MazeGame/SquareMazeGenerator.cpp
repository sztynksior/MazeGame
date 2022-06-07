#include "SquareMazeGenerator.h"

MazeCell* SquareMazeGenerator::getAccessToCellIndicatedByVector(const std::pair<int, int> pCellCoordinates, const  std::pair<int, int> pIndicativeVector)
{
	return maze[pCellCoordinates.first + pIndicativeVector.first][pCellCoordinates.second + pIndicativeVector.second];
}

SquareMazeGenerator::SquareMazeGenerator(const int pMaxMazeX, const int pMaxMazeY, const std::pair<int, int>& pStartingCoordinates, const std::pair<int, int>& pFinishCoordinateS)
	: MazeGenerator(pMaxMazeX, pMaxMazeY, pStartingCoordinates, pFinishCoordinateS)
{
	for (int i = 0; i < this->maxMazeX; i++)
	{
		maze.push_back(std::vector<MazeCell*>());
		for (int j = 0; j < this->maxMazeY; j++)
		{
			this->maze[i].push_back(new SquareMazeCell({ i, j }));
		}
	}

	this->mazeInicialization();
}

SquareMazeGenerator::~SquareMazeGenerator()
{
}

int SquareMazeGenerator::getMaxMazeX()
{
	return this->maxMazeX;
}

int SquareMazeGenerator::getMaxMazeY()
{
	return this->maxMazeY;
}

MazeCell* SquareMazeGenerator::getAccessToCellWithGivenCoordinates(std::pair<int, int> pCoordinates)
{
	return maze[pCoordinates.first][pCoordinates.second];
}

void SquareMazeGenerator::mazeInicialization()
{
	srand(time(NULL));

	std::stack<std::pair<int, int>> cellsOnStack;
	const int numberOfCellsToVisit = this->maxMazeX * this->maxMazeY;
	int numberOFVisitedCells = 0;

	cellsOnStack.push(maze[this->startingCoordinates.first][this->startingCoordinates.second]->getCoordinates());

	while (numberOFVisitedCells < numberOfCellsToVisit)
	{
		std::vector<std::pair<int, int>> notVisitedNeighbours;

		this->lookingForNeighbours(notVisitedNeighbours, cellsOnStack.top());

		//TO DO: przenieœ tego ifa do osobnej funkcji

		if (!notVisitedNeighbours.empty())
		{
			std::pair<int, int> nextNeighbour = notVisitedNeighbours[rand() % notVisitedNeighbours.size()]; //TO DO: zmieñ nazwe i sprawdŸ czy rand zwraca za ka¿dym razem inn¹ wartoœæ

			this->getAccessToCellIndicatedByVector(cellsOnStack.top(), nextNeighbour)->wasVisited();
			this->getAccessToCellIndicatedByVector(cellsOnStack.top(), nextNeighbour)->addNeighbour({ nextNeighbour.first * -1, nextNeighbour.second * -1 });

			this->getAccessToCellWithGivenCoordinates(cellsOnStack.top())->addNeighbour(nextNeighbour);

			cellsOnStack.push(this->getAccessToCellIndicatedByVector(cellsOnStack.top(), nextNeighbour)->getCoordinates());

			numberOFVisitedCells++;
		}
		else
		{
			cellsOnStack.pop();
		}
	}
}

void SquareMazeGenerator::lookingForNeighbours(std::vector<std::pair<int, int>>& pNotVisitedNeighbours, std::pair<int, int> pCellCoordinates)
{
	//looking for top neighbour
	if (pCellCoordinates.second > 0 and this->getAccessToCellIndicatedByVector(pCellCoordinates, { 0, -1 })->whetherItWasVisited() == false)
	{
		pNotVisitedNeighbours.push_back({ 0, -1 });
	}

	//looking for right neighbour
	if (pCellCoordinates.first < (this->maxMazeX - 1) and this->getAccessToCellIndicatedByVector(pCellCoordinates, { 1, 0 })->whetherItWasVisited() == false)
	{
		pNotVisitedNeighbours.push_back({ 1, 0 });
	}

	//looking for bottom neighbour
	if (pCellCoordinates.second < (this->maxMazeY - 1) and this->getAccessToCellIndicatedByVector(pCellCoordinates, { 0, 1 })->whetherItWasVisited() == false)
	{
		pNotVisitedNeighbours.push_back({ 0, 1 });
	}

	//looking for left neighbour
	if (pCellCoordinates.first > 0 and this->getAccessToCellIndicatedByVector(pCellCoordinates, { -1, 0 })->whetherItWasVisited() == false)
	{
		pNotVisitedNeighbours.push_back({ -1, 0 });
	}
}
