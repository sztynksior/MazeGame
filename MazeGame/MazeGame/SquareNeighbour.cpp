#include "SquareNeighbour.h"

SquareNeighbour::SquareNeighbour(std::pair<int, int> pPointingVector) : Neighbour(pPointingVector)
{
}

SquareNeighbour::~SquareNeighbour()
{
}

std::pair<int, int> SquareNeighbour::getPointingVector()
{
	return this->pointingVector;
}
