#include "SquareMazeCell.h"

SquareMazeCell::SquareMazeCell(const std::pair<int, int> pCoordinates) : MazeCell(pCoordinates)
{
}

SquareMazeCell::~SquareMazeCell()
{
}

std::pair<int, int> SquareMazeCell::getCoordinates()
{
	return this->coordinates;
}

void SquareMazeCell::wasVisited()
{
	this->isVisited = true;
}

bool SquareMazeCell::whetherItWasVisited()
{
	return this->isVisited;
}

int SquareMazeCell::numberOfNeigbours()
{
	return this->neighbours.size();
}

std::pair<int, int> SquareMazeCell::getNeigbourFromTable(const int pIterator)
{
	return this->neighbours[pIterator];
}

void SquareMazeCell::addNeighbour(std::pair<int, int> pNeighbourVector)
{
	this->neighbours.push_back(pNeighbourVector);
}