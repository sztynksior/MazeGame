#ifndef SQUARENEIGHBOUR_H
#define SQUARENEIGHBOUR_H

#include "Neighbour.h"
#include <utility>

class SquareNeighbour : public Neighbour
{
	std::pair<int, int> indicativeVector;

public:
	SquareNeighbour(std::pair<int, int> pPointingVector);
	~SquareNeighbour();

	std::pair<int, int> getPointingVector();
};
#endif // !SQUARENEIGHBOUR_H


