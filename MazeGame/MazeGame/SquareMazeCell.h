#ifndef SQUAREMAZECELL_H
#define SQUAREMAZECELL_H

#include "MazeCell.h"
#include <utility>
#include <unordered_map>

class SquareMazeCell : public MazeCell
{
public:

	SquareMazeCell(const std::pair<int, int> pCoordinates);
	~SquareMazeCell();

	std::pair<int, int> getCoordinates();
	void wasVisited();
	bool whetherItWasVisited();
	int numberOfNeigbours();
	std::pair<int, int> getNeigbourFromTable(const int pIterator);
	void addNeighbour(std::pair<int, int> pNeighbourVector);
};

#endif // !SQUAREMAZECELL_H