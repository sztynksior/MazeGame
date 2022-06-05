#include "MazeCell.h"

MazeCell::MazeCell(const std::pair<int, int> pCoordinates)
{
	this->isVisited = false;
	this->coordinates = pCoordinates;
}

MazeCell::~MazeCell()
{
}