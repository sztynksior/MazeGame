#include "SquareMazeGenerator.h"

MazeCell* SquareMazeGenerator::getAccessToCellIndicatedByVector(const std::pair<int, int> pCellCoordinates, const  std::pair<int, int> pVector)
{
	return maze[pCellCoordinates.first + pVector.first][pCellCoordinates.second + pVector.second];
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
}

SquareMazeGenerator::~SquareMazeGenerator()
{
	for (int i = 0; i < this->maxMazeX; i++)
	{
		for (int j = 0; j < this->maxMazeY; j++)
		{
			delete this->maze[i][j];
		}
	}
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
	std::stack<std::pair<int, int>> cellsOnStack;
	const int numberOfCellsToVisit = this->maxMazeX * this->maxMazeY;
	int numberOFVisitedCells = 0;

	cellsOnStack.push(maze[this->startingCoordinates.first][this->startingCoordinates.second]->getCoordinates());

	while (numberOFVisitedCells < numberOfCellsToVisit)
	{
		std::vector<Neighbour*> notVisitedNeighbours;

		//TO DO: przenieœ te ify do osobnej funkcji

		//looking for top neighbour
		if (cellsOnStack.top().second > 0 and this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0, -1 })->whetherItWasVisited() == false)
		{
			notVisitedNeighbours.push_back(fromWhichSide::Top);
		}

		//looking for right neighbour
		if (cellsOnStack.top().first < (this->maxMazeX - 1) and this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 1, 0 })->whetherItWasVisited() == false)
		{
			notVisitedNeighbours.push_back(fromWhichSide::Right);
		}

		//looking for bottom neighbour
		if (cellsOnStack.top().second < (this->maxMazeY - 1) and this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0, 1 })->whetherItWasVisited() == false)
		{
			notVisitedNeighbours.push_back(fromWhichSide::Bottom);
		}

		//looking for left neighbour
		if (cellsOnStack.top().first > 0 and this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { -1, 0 })->whetherItWasVisited() == false)
		{
			notVisitedNeighbours.push_back(fromWhichSide::Left);
		}

		//TO DO: przenieœ tego ifa do osobnej funkcji

		if (!notVisitedNeighbours.empty())
		{
			fromWhichSide nextNeighbour = notVisitedNeighbours[rand() % notVisitedNeighbours.size()]; //TO DO: zmieñ nazwe i sprawdŸ czy rand zwraca za ka¿dym razem inn¹ wartoœæ

			switch (nextNeighbour)
			{
			case fromWhichSide::Top:
			{
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0, -1 })->wasVisited();
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0, -1 })->addNeighbour(fromWhichSide::Bottom);

				this->getAccessToCellWithGivenCoordinates(cellsOnStack.top())->addNeighbour(fromWhichSide::Top);

				cellsOnStack.push(this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0 , -1 })->getCoordinates());

				break;
			}
			case fromWhichSide::Right:
			{
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 1, 0 })->wasVisited();
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 1, 0 })->addNeighbour(fromWhichSide::Left);

				this->getAccessToCellWithGivenCoordinates(cellsOnStack.top())->addNeighbour(fromWhichSide::Right);

				cellsOnStack.push(this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 1 , 0 })->getCoordinates());

				break;
			}
			case fromWhichSide::Bottom:
			{
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0, 1 })->wasVisited();
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0, 1 })->addNeighbour(fromWhichSide::Top);

				this->getAccessToCellWithGivenCoordinates(cellsOnStack.top())->addNeighbour(fromWhichSide::Bottom);

				cellsOnStack.push(this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { 0 , 1 })->getCoordinates());

				break;
			}
			case fromWhichSide::Left:
			{
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { -1, 0 })->wasVisited();
				this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { -1, 0 })->addNeighbour(fromWhichSide::Right);

				this->getAccessToCellWithGivenCoordinates(cellsOnStack.top())->addNeighbour(fromWhichSide::Left);

				cellsOnStack.push(this->getAccessToCellIndicatedByVector(cellsOnStack.top(), { -1 , 0 })->getCoordinates());

				break;
			}
			}

			numberOFVisitedCells++;
		}
		else
		{
			cellsOnStack.pop();
		}
	}
}