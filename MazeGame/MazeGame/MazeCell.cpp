#include "MazeCell.h"

MazeCell::MazeCell(const std::pair<int, int> pCoordinates)
{
	this->isVisited = false;
	this->coordinates = pCoordinates;
}

MazeCell::~MazeCell()
{
}

std::pair<int, int> MazeCell::getCoordinates()
{
	return this->coordinates;
}

void MazeCell::wasVisited()
{
	this->isVisited = true;
}

bool MazeCell::whetherItWasVisited()
{
	return this->isVisited;
}

int MazeCell::numberOfNeigbours()
{
	return this->neighbours.size();
}

fromWhichSide MazeCell::getNeigbourFromVector(const int pIterator)
{
	return this->neighbours[pIterator];
}

void MazeCell::addNeighbour(fromWhichSide pFromWhichSide)
{
	this->neighbours.push_back(pFromWhichSide);
}
