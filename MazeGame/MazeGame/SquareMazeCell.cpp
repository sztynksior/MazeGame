#include "SquareMazeCell.h"

SquareMazeCell::SquareMazeCell(const std::pair<int, int> pCoordinates) : MazeCell(pCoordinates)
{
	this->posibleNeighbours.insert({ "TOP_NEIGHBOUR", new SquareNeighbour({0, -1}) });
	this->posibleNeighbours.insert({ "RIGHT_NEIGHBOUR", new SquareNeighbour({ 1, 0 }) });
	this->posibleNeighbours.insert({ "BOTTOM_NEIGHBOUR", new SquareNeighbour({ 0, 1 }) });
	this->posibleNeighbours.insert({ "LEFT_NEIGHBOUR", new SquareNeighbour({ -1, 0 }) });
}

SquareMazeCell::~SquareMazeCell()
{
	for (std::pair<std::string, Neighbour*> it : this->posibleNeighbours)
	{
		delete it.second;
	}
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

Neighbour* SquareMazeCell::getNeigbourFromTable(const int pIterator)
{
	return this->neighbours[pIterator];
}

void SquareMazeCell::addNeighbour(std::string pNeighbourType)
{
	this->neighbours.push_back(this->posibleNeighbours[pNeighbourType]);
}
